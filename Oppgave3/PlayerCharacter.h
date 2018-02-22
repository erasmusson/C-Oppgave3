#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "HP.h"

using namespace std;
class Character
{
public:
	Character(int hp, int ac, int maxhp, string name);
	int hit();
	string getName() const;
	HP getHP();
	void setHP(int sum);
	//void setHP(int z);
	//int getMaxHP() const;
	virtual string runTurn() = 0;
	virtual bool isAI() = 0;
	~Character();

private:
	string m_name;
	HP m_hp;
};

