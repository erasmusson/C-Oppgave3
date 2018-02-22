#include "stdafx.h"
#include "NPC.h"


NPC::NPC(int hp, int ap, int maxhp, string name) : Character(hp, ap, maxhp, name)
{
	GameManager &gm = GameManager::Instance();
	srand((unsigned)time(0));

	// Chooses which target to pick. Makes sure that it not picks itself.
	if (gm.getPlayers().size() > 1) {
		bool AISelf = true;
		while (AISelf) {
			m_currentTarget = rand() % ((gm.getPlayers().size()) - 1) + 1;
			auto attacked = gm.getPlayers().at(m_currentTarget);
			if (!(attacked->isAI())) {
				AISelf = false;
			}
		}
	}
	else {
		m_currentTarget = 0;
	}
}

NPC::~NPC()
{
}

bool NPC::isAI()
{
	return true;
}

// Runs turn and attacks or dogdes an attack.
string NPC::runTurn()
{
	stringstream ss;
	srand((unsigned)time(0));
	int action = rand() % 2 + 1;

	//Attacks it's target.
	if (action == 1) {
		auto players = GameManager::Instance().getPlayers();
		auto attacked = players.at(m_currentTarget);
		int hit = NPC::hit();
		attacked->setHP(hit);
		ss << NPC::getName() << " attacked " << attacked->getName() << " for " << hit << " in damage." << endl;
	}	
	//Tries to dogde an attack. Succeeds if the random number is over 25.
	else {
		int hit = NPC::hit();
		if (hit > 25) {
			ss << NPC::getName() << " dogdes an attack " << endl;
			HP playersHp = NPC::getHP();
			if ((playersHp.getHP() + hit) < playersHp.getMaxHp()) {
				playersHp += hit;
			}
			else {
				playersHp += playersHp.getMaxHp();
			}
		}
		else {
			ss << NPC::getName() << " fails to dogde an attack " << endl;
		}
	}
	
	return ss.str();

}


