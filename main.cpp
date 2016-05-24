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
	Encounter fight;












	fight.yourHero(gladiator.name());
	cout<<endl;
	fight.yourHero(enemy_no1.name());
	cout<<endl;
	fight.yourHero(enemy_no2.name());
	cout<<endl;
	fight.yourHero(enemy_no3.name());
	cout<<endl;
	fight.yourHero(anim_one.name());
	cout<<endl;
	fight.yourHero(cent.name());
	cout<<endl;

	fight.victory_message(gladiator.name());
	fight.loss_message(gladiator.name(), cent.name());
}
