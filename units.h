#pragma once

#include <string>
#include <vector>

using namespace std;

class Unit
{
	public:
		static vector <string> names;

		string _name;
		int _hp, totalHp;
		int _attackPower, _defencePower;
		static void init();

		int hp() {return _hp;}
		string name() {return _name;}
		int attackPower() {return _attackPower;}
		int defencePower() {return _defencePower;}

		bool areYouDead(int value);

		
};

/*class Encounter
{
	private:
		int encounter_number = 0;
	public:
		void yourHero();
		void combat();
		void victory_message();
		void loss_message();

};*/

class Hero : public Unit
{
	private:
		int _luck;
		void victoryAward();
	public:
		Hero();
};

class Glad : Unit
{
	private:
		int hitChance();
	public:
		Glad();
};
