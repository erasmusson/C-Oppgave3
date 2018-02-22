#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "PlayerCharacter.h"

using namespace std;
class GameManager
{
public:
	static GameManager& Instance() { 
		static GameManager gameManager;
		return gameManager;
	}
	void startGame();
	void runGame();
	vector<shared_ptr<Character>>& getPlayers();
	bool checkHPStats();
	void deleteLists();

private:
	GameManager(){}
	GameManager(const GameManager&) = delete;	
	GameManager& operator=(const GameManager&) = delete;
	~GameManager();
	int m_AmoutOfPlayers;
	vector<shared_ptr<Character>> m_players;
};
