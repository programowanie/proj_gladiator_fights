#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "units.h"

using namespace std;

int main(int argc, char **argv)
{
	srand(time(NULL));

	Hero gladiator;

	Glad enemy;

	Animal beast;

	Centurion boss;

	Encounter fight;

		fight.nameOfHero=gladiator._name;
		fight.yourHero(gladiator._name);

		for(int i=0; i<3; i++)
		{
			enemy.powerup(fight.encounter_number(), enemy.totalHp, enemy._attackPower, enemy._defencePower);

			fight.combatLoop(gladiator._hp, gladiator._attackPower, gladiator._defencePower,
						enemy._hp, enemy._attackPower, enemy._defencePower);
		}
		

}
