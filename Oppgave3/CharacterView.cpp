#include "stdafx.h"
#include "CharacterView.h"

// Initilize new players. 
void CharacterView::promtNewPlayers(int m_AmoutOfPlayers)
{
	cout << "Initializing " << m_AmoutOfPlayers << " players." << endl;
	for (int i = 0; i < m_AmoutOfPlayers; i++) {
		int charClass; string name;

		cout << "Player Classes" << endl << "1 - Wizard" << endl << "2 - Troll" << endl << "3 - Assassin" << endl << "Pick player no " << (i + 1) << " class: ";
		cin >> charClass;

		if (charClass == 1 || charClass == 2 || charClass == 3) {
			cout << "Write player " << (i + 1) << " name: ";
			cin.ignore();
			getline(cin, name);
			createPlayer(charClass, name);
		}
		else { cout << "There is no class like the one you've chosen. Player not registered."; }
	}
	createAI();
}

// Asks user for action and rurns users turn and AI's turn.
void CharacterView::promtAction()
{
	cout << "Actions: " << endl << "1 - Attack" << endl << "2 - Dogde" << endl;
	stringstream ss;

	auto iter = sm.getPlayers().begin();
	while (iter != sm.getPlayers().end()) {

		// If it's not AI then ask user for action.
		if (!(*iter)->isAI()) {
			ss << (*iter)->runTurn();
			++iter;
		}
		else {
			ss  << (*iter)->runTurn();
			++iter;
		}
	}

	//printout output
	cout << ss.str() << endl;
	ss.str("");
}

//Prints out current HP of players.
void CharacterView::printStatus()
{
	vector<shared_ptr<Character>> m_players = sm.getPlayers();

	auto iter = m_players.begin();
	int pos = 1;
	while (iter != m_players.end()) {
		cout << (*iter)->getName() << " #" << pos << "    " << (*iter)->getHP().getHP() << " / " << (*iter)->getHP().getMaxHp() << endl;
		++pos;
		++iter;
	}
}

//Creates different classes of players with different hp, ac.
void CharacterView::createPlayer(int charClass, string name)
{
	switch (charClass) {
		//Wizard
		case 1: {
			shared_ptr<PCharacter> p(new PCharacter(100, 30, 100, name));
			sm.getPlayers().push_back(move(p));
			break;
		}	
		//Troll
		case 2: {
			shared_ptr<PCharacter> p(new PCharacter(500, 20, 100, name));
			sm.getPlayers().push_back(move(p));
			break;
		}
		//Assasain
		case 3: {
			shared_ptr<PCharacter> p(new PCharacter(100, 40, 100, name));
			sm.getPlayers().push_back(move(p));
			break;
		}
	}
}

//Creates an AI.
void CharacterView::createAI()
{
	shared_ptr<NPC> p(new NPC(100, 20, 100, "AI"));
	sm.getPlayers().push_back(move(p));
}

CharacterView::CharacterView()
{
}

CharacterView::~CharacterView()
{
}
