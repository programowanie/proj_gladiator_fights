#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "units.h"

using namespace std;

int main(int argc, char **argv)
{
	srand(time(NULL));

	Hero gladiator;
	Glad enemy_no1, enemy_no2, enemy_no3;
	Animal anim_one;
	Centurion cent;
	Encounter fight_one;

		fight_one.nameOfHero=gladiator.name();
		fight_one.yourHero(gladiator.name());


		fight_one.combatLoop(gladiator.hp(), gladiator.attackPower(), gladiator.defencePower(), enemy_no1.hp(), enemy_no1.attackPower(), enemy_no1.defencePower());


}
