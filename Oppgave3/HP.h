#pragma once
#include <iostream>
using namespace std;
class HP
{
public:
	HP(int hp, int ac, int maxhp);
	~HP();
	int getMaxHp() const;
	int getHP();
	void operator-=(int i);
	void operator += (const int i);
	bool operator == (const int i) const;
	friend bool operator == (const int i, const HP& h);
	void printStatus();

private:
	int m_hp;
	int m_ac;
	int m_maxhp;
};



