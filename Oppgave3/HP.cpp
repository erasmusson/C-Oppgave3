#include "stdafx.h"
#include "HP.h"


HP::HP(int hp, int ac, int maxhp)
{
	m_hp = hp;
	m_ac = ac;
	m_maxhp = maxhp;
}

HP::~HP()
{
}

int HP::getMaxHp() const
{
	return m_maxhp;
}

int HP::getHP()
{
	return m_hp;
}

//implementerer skade.Den skal trekke AC fra skaden før den trekker skaden fra HP.
void HP::operator-=(int i)
{
	if ((i - m_ac) > 0) {
		m_hp = (m_hp - i + m_ac);
	}
}

//implementerer healing.Den skal legge int’en direkte til på HP - verdien, HP kan ikke bli høyere enn verdien den ble inisialisert til.
void HP::operator+=(const int i) 
{
	if ((i + m_hp) <= m_maxhp) {
		 m_hp = i + m_hp;
	}
	else {
		m_hp = m_maxhp;
	}
}

//sammenlikne med en int, denne skal kunne stå på begge sider, og sammenlikner bare HP - verdien med int’en
bool HP::operator==(const int i) const
{
	if (i == m_hp) {
		cout << "true";
		return true;
	}
	else {
		cout << "false";
		return false;
	}
}

// Prints status about the player such as AC, HP and Max HP.
void HP::printStatus()
{
	cout << "HP : " << m_hp << " MHP : " << m_maxhp << " AC : " << m_ac << endl;
}

bool operator==(const int i, const HP & h)
{
	if (i == h.m_hp) {
		cout << "true";
		return true;
	}
	else {
		cout << "false";
		return false;
	}
}
