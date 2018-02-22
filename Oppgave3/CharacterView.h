#pragma once
#include <iostream>
#include <string>
#include "PCharacter.h"
#include "GameManager.h"
#include <memory>
#include <sstream>
#include "NPC.h"

using namespace std;

class CharacterView
{
public:
	void promtNewPlayers(int m_AmountOfPlayers);
	void promtAction();
	void printStatus();
	void createPlayer(int charClass, string name);
	void createAI();
	CharacterView();
	~CharacterView();
private:
	GameManager & sm = GameManager::Instance();
};

