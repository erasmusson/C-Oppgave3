#include "stdafx.h"
#include "PCharacter.h"



// Chooses target and action and does it.
string PCharacter::runTurn()
{
	stringstream ss;
	auto gm = GameManager::Instance().getPlayers();

	int action;
	cout << PCharacter::getName() << " pick an action: ";
	cin >> action;
	cout << "Pick a target: " << endl;

	// Print out targets names.
	auto nameIter = gm.begin();
	int pos = 0;

	while (nameIter != gm.end()) {
		if ((*nameIter)->getName().compare(PCharacter::getName()) != 0) {
			cout << (pos + 1) << " - " << (*nameIter)->getName() << endl;
		}
		pos++;
		++nameIter;
	}

	//Choose target
	int target;
	cin >> target;
	if (action == 1) {
		auto attacked = gm.at(target - 1);
		int hit = PCharacter::hit();
		attacked->setHP(hit);
		ss << PCharacter::getName() << " attacked " << attacked->getName() << " for " << hit << " in damage." << endl;
	}
	else {
		int hit = PCharacter::hit();
		if (hit > 25) {
			ss << PCharacter::getName() << " dogdes an attack " << endl;
			HP playersHp = PCharacter::getHP();

			if ((playersHp.getHP() + hit) < playersHp.getMaxHp()) {
				playersHp += hit;
			}
			else {
				playersHp += playersHp.getMaxHp();
			}
		}
		else {
			ss << PCharacter::getName() << " fails to dogde an attack " << endl;
		}
	}

	return ss.str();
}

bool PCharacter::isAI()
{
	return false;
}

PCharacter::PCharacter(int hp, int ap, int maxhp, string name) : Character(hp, ap, maxhp, name)
{

}

PCharacter::~PCharacter()
{
}
