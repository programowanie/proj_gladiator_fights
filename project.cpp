#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "units.h"
#include <iterator>

using namespace std;

vector <string> Unit::names;

void Unit::init()
{
	ifstream file("roman_names.txt");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
}

Hero::Hero()
{
	static int amountOfNames = (init(), names.size());
	_name = names[rand() % amountOfNames];
	_hp = totalHp = 150 + rand() % 75;
	_attackPower = 20 + rand() % 30;
	_defencePower = 50 + rand() % 30;
	_luck = 10 + rand() % 20;
}

Glad::Glad()
{
	static int amountOfNames = (init(), names.size());
	_name = names[rand() % amountOfNames];
	_hp = totalHp = 70 + rand() % 50;
	_attackPower = 20 + rand() % 30;
	_defencePower = 40 + rand() % 20;
}

int Glad::hitChance()
{
	int value;
	value = 20 + rand() % 80;
	return value;
}

void Hero::victoryAward()
{
	int heal = (totalHp)/5;

	if(_hp>(totalHp - heal))
		_hp=totalHp;

	else
		_hp+=(totalHp)/5;
}

/*void Encounter::yourHero()
{
	Hero gladiator;
	cout<<"Your hero's name is "<<gladiator._name<<"!"<<endl;
}*/