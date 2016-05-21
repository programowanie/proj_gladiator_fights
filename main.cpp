#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "units.h"

using namespace std;

int main(int argc, char **argv)
{
	srand(time(NULL));

	Hero gladiator;
	cout<<"Imie to "<<gladiator.name()<<endl<<"Staty "<<gladiator.attackPower()<<endl<<gladiator.defencePower()<<endl;
}
