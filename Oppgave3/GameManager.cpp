#include "stdafx.h"
#include "GameManager.h"
#include "CharacterView.h"


// Prints information about game and call method to create players
void GameManager::startGame()
{
	CharacterView m_cv;
	cout << "Turnventrue v1.0" << endl << "Enter numbers of players(minimum 1 and maximum 7): ";
	cin >> m_AmoutOfPlayers;

	if (m_AmoutOfPlayers > 0 || m_AmoutOfPlayers < 7) {
		m_cv.promtNewPlayers(m_AmoutOfPlayers);
	}
	else {
		cout << "Too many or too little players." << endl;
	}
	
}

// Runs game until there is only on player with HP.
void GameManager::runGame()
{
	int rounds = 1;
	bool playing = true;
	CharacterView m_cv;

	while (playing) {
		cout << "Round " << rounds << endl;
		
		m_cv.printStatus();

		m_cv.promtAction();

		playing = GameManager::checkHPStats();	
	}
}

//Checks HP stats for every round. If a player has 0 in hp they are declared dead.
bool GameManager::checkHPStats() 
{
	for (auto iter = m_players.begin(); iter != m_players.end(); iter++) {
		if ((*iter)->getHP().getHP() < 0) {
			cout << (*iter)->getName() << " is dead." << endl;
			(*iter).reset();
			iter = m_players.erase(iter);
		}
		if ((m_players.size()) <= 1) {
			auto winner = m_players.begin();
			cout << (*winner)->getName() << " is the winner." << endl;
			return false;
		}
	}
	return true;
}

// returns players.
vector<shared_ptr<Character>>& GameManager::getPlayers()
{
	return m_players;
}

//Deletes all members in the list.
void GameManager::deleteLists()
{
	auto iter = m_players.begin();
	cout << "Here in destructor" << endl;
	while (iter != m_players.end()) {
		cout << "I deleted " << (*iter)->getName() << endl;
		(*iter).reset();
		iter = m_players.erase(iter);
	}
}

GameManager::~GameManager()
{
	GameManager::deleteLists();
}
