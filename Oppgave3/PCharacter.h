#pragma once
#include "PlayerCharacter.h"
#include "GameManager.h"
using namespace std;

class PCharacter : public Character
{
public:
	string runTurn() override;
	bool isAI() override;
	PCharacter(int hp, int ap, int maxhp, string name);
	~PCharacter();
};

