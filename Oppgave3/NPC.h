#pragma once
#include "PlayerCharacter.h"
#include <cstdlib>
#include <ctime> 
#include "GameManager.h"

using namespace std;
class NPC : public Character
{
public:
	NPC(int hp, int ap, int maxhp, string name);
	~NPC();
	bool isAI() override;
	virtual string runTurn() override;
private:
	int m_currentTarget;
};

