#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "units.h"
#include <iterator>
#include <unistd.h>

#define Slow 2000000
#define Slower 4000000

using namespace std;

vector <string> Unit::names;
vector <string> Unit::animal_names;

void Unit::init()
{
	ifstream file("roman_names.txt");
	ifstream filetwo("animal_names.txt");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	copy(istream_iterator<string>(filetwo),
		istream_iterator<string>(),
		back_inserter(animal_names));
	file.close();
	filetwo.close();
}
Centurion::Centurion()
{
	static int amountOfNames = (init(), names.size());
	_name = names[rand() % amountOfNames];
	_hp = totalHp = 120 + rand() % 80;
	_attackPower = 20 + rand() % 30;
	_defencePower = 50 + rand() % 30;	
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
	_defencePower = 60 + rand() % 20;
}

Animal::Animal() 								
{
	static int amountOfAnimalNames = (init(), animal_names.size());
	_name = animal_names[rand() % amountOfAnimalNames];
	_hp = totalHp = 100 + rand() % 50;
	_attackPower = 40 + rand() % 60;
	_defencePower = 10 + rand() % 30;
}

void Encounter::enrage(int & atk, int & def)	//Zmieniłem enrage na 50% co by ciekawiej było :v
{
	atk+=atk/2;
	def+=def/2;
}

int Encounter::hitChance()
{
	int value;
	value = 20 + rand() % 80;
	return value;
}

void Hero::victoryAward()
{
	cout<<"Thanks to his efforts "<<_name<<" is able to regenerate some of his health!"<<endl;
	int heal = (totalHp)/5;

	if(_hp>(totalHp - heal))
		_hp=totalHp;

	else
		_hp+=(totalHp)/5;
}

void Encounter::yourHero(string sentence)
{
	cout<<"Today a challenger will have a chance of winning his freedom!"<<endl; usleep(Slower);
	cout<<"This gladiator's name is "<<sentence<<"!"<<endl; usleep(Slow);
}

void Encounter::final_victory_message(string name)
{
	cout<<name<<" has defeated each and every of his enemies! From this moment on, he shall be called free man!"<<"\t YOU WIN!"<<endl;
}

void Encounter::victory_message(string name)
{
	cout<<name<<" was victorious!"<<endl;
}

void Encounter::loss_message(string hero, string enemy)
{
	cout<<"Brave "<<hero<<" has been awfully killed by "<<enemy<<"!"<<"\t YOU LOSE!"<<endl;
}

int Encounter::encounter_number()
{
	int value=0;

	value = _encounter_number;

	_encounter_number+=1;
	return value;
}

bool Encounter::areYouDead(int value)
{
	if(value<=0)
		return 1;
	else return 0;
}

int Glad::powerup(int value, int & maxhp, int & attack, int & def)
{
	switch(value)
	{
		case 2:
		{
			maxhp+=maxhp/10;
			attack+=attack/10;
			def+=def/10;
		} return maxhp, attack, def;

		case 3:
		{
			maxhp+=maxhp/5;
			attack+=attack/5;
			def+=def/5;
		} break;
	}
}

int Encounter::damage_received(int dmg, int armor)
{
	double value;

	value=(double)dmg/(double)armor;

	return dmg*value*hittedSpotMultiplation();
}

double Encounter::hittedSpotMultiplation()
{
	double val1, val2;

	val1 = 3 + rand() % 3;
	val2 = 3 + rand() % 3;

	double value = val1/val2;
	return value;
}

void Encounter::combatLoop(int & heroHp, int heroDmg, int heroDef, int heroLuck,
							int enemyHp, int enemyDmg, int enemyDef, int which_fight)
{
	int totalEnemyHp = enemyHp;
	while(1)
	{

		if(which_fight==4 && enemyHp<totalEnemyHp/3)
		{
			cout<<nameOfEnemy<<" is furious and goes into enrage!!!"<<endl;
			enrage(enemyDmg, enemyDef);
			which_fight++;
		};

		int hpLoss=damage_received(heroDmg, enemyDef);
		
		usleep(Slow);

		cout<<nameOfHero<<" dealed "<<hpLoss<<" damage to "<<nameOfEnemy<<endl;

		enemyHp-=hpLoss;

		cout<<"\t"<<"|"<<"Hero HP"<<"\t"<<"Enemy HP"<<"|"<<endl
				<<"\t"<<"|"<<heroHp<<"\t\t"<<enemyHp<<"\t"<<"|"<<endl;

		if(areYouDead(enemyHp))
		{
			victory_message(nameOfHero);
			break;
		};

		if(heroLuck*3>=hitChance())
		{
			usleep(Slow);

			cout<<nameOfHero<<" dodges his opponents attack!!"<<endl;
			continue;
		} else
		{
			hpLoss=damage_received(enemyDmg, heroDef);

			usleep(Slow);

			cout<<nameOfEnemy<<" dealed "<<hpLoss<<" damage to "<<nameOfHero<<endl;

			heroHp-=hpLoss;

			cout<<"\t"<<"|"<<"Hero HP"<<"\t"<<"Enemy HP"<<"|"<<endl
			<<"\t"<<"|"<<heroHp<<"\t\t"<<enemyHp<<"\t"<<"|"<<endl;

			if(areYouDead(heroHp))
			{
				loss_message(nameOfHero, nameOfEnemy);
				break;
			};
		};
	}
}