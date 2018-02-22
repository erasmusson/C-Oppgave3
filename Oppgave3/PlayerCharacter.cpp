#include "stdafx.h"
#include "PlayerCharacter.h"
#include <cstdlib>
#include <ctime> 

Character::Character(int hp, int ac, int maxhp, string name) : m_hp(hp, ac, maxhp)
{
	m_name = name;
}

Character::~Character()
{
}

//Creates a random number which is the hitpoints for this attack.
int Character::hit()
{
	srand((unsigned int)time(0));
	return (rand() % 60) + 1;
}

//returns the name.
string Character::getName() const
{
	return m_name;
}

//returns the HP object.
HP Character::getHP()
{	
	return m_hp;
}

//Changes HP
void Character::setHP(int sum)
{
	m_hp -= sum;
}

