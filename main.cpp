#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "units.h"
#include <unistd.h>

#define Slow 1000000
#define Slower 4000000

using namespace std;

int main(int argc, char **argv)
{
	srand(time(NULL));

	Hero gladiator;

	Glad enemy, enemy2, enemy3;

	Animal beast;

	Centurion boss;

	Encounter fight;

	fight.nameOfHero=gladiator._name;
	fight.yourHero(gladiator._name);

	for(int i=0; i<=4; i++)
	{
		switch(i)
		{
			case 0:
			{
				cout<<"First fight is about to start!"<<endl; usleep(Slower);

				fight.nameOfEnemy=enemy._name;

				cout<<fight.nameOfHero<<" will be fighting with "<<fight.nameOfEnemy<<endl; usleep(Slower);

				cout<<"FIGHT!"<<endl; usleep(Slow);

				enemy.powerup(fight.encounter_number(), enemy.totalHp, enemy._attackPower, enemy._defencePower);

				fight.combatLoop(gladiator._hp, gladiator._attackPower, gladiator._defencePower,
								gladiator.luck(), enemy.totalHp, enemy._attackPower, enemy._defencePower, i);
			} break;

			case 1:
			{
				if(fight.areYouDead(gladiator._hp))
				{
					return 0;
				};

				gladiator.victoryAward();

				fight.nameOfEnemy=enemy2._name;

				cout<<"Second fight is about to start!"<<endl; usleep(Slower);

				cout<<fight.nameOfHero<<" will be fighting with "<<fight.nameOfEnemy<<endl; usleep(Slower);

				cout<<"FIGHT!"<<endl; usleep(Slow);

				enemy2.powerup(fight.encounter_number(), enemy2.totalHp, enemy2._attackPower, enemy2._defencePower);

				fight.combatLoop(gladiator._hp, gladiator._attackPower, gladiator._defencePower,
								gladiator.luck(), enemy2.totalHp, enemy2._attackPower, enemy2._defencePower, i);
			} break;

			case 2:
			{
				if(fight.areYouDead(gladiator._hp))
				{
					return 0;
				};

				gladiator.victoryAward();

				fight.nameOfEnemy=enemy3._name;

				cout<<"Third fight is about to start!"<<endl; usleep(Slower);

				cout<<fight.nameOfHero<<" will be fighting with "<<fight.nameOfEnemy<<endl; usleep(Slower);

				cout<<"FIGHT!"<<endl; usleep(Slow);

				enemy2.powerup(fight.encounter_number(), enemy3.totalHp, enemy3._attackPower, enemy3._defencePower);

				fight.combatLoop(gladiator._hp, gladiator._attackPower, gladiator._defencePower,
								gladiator.luck(), enemy3.totalHp, enemy3._attackPower, enemy3._defencePower, i);
			} break;

			case 3:
			{
				if(fight.areYouDead(gladiator._hp))
				{
					return 0;
				};

				gladiator.victoryAward();

				fight.nameOfEnemy=beast._name;

				cout<<"Fourth fight is about to start!"<<endl; usleep(Slower);

				cout<<fight.nameOfHero<<" will be fighting with "<<fight.nameOfEnemy<<endl; usleep(Slower);

				cout<<"FIGHT!"<<endl; usleep(Slow);

				fight.combatLoop(gladiator._hp, gladiator._attackPower, gladiator._defencePower,
								gladiator.luck(), beast.totalHp, beast._attackPower, beast._defencePower, i);
			} break;

			case 4:
			{
				if(fight.areYouDead(gladiator._hp))
				{
					return 0;
				};

				gladiator.victoryAward();

				fight.nameOfEnemy=boss._name;

				cout<<"Final fight is about to start!"<<endl; usleep(Slower);

				cout<<fight.nameOfHero<<" will be fighting with "<<fight.nameOfEnemy<<endl; usleep(Slower);

				cout<<"FIGHT!"<<endl; usleep(Slow);

				fight.combatLoop(gladiator._hp, gladiator._attackPower, gladiator._defencePower,
								gladiator.luck(), boss.totalHp, boss._attackPower, boss._defencePower, i);

				if(gladiator._hp>0)
					fight.final_victory_message(gladiator._name);
			} break;
		}		
	}

}