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

class Encounter
{
	private:
		int _encounter_number = 1;
	public:
		int encounter_number() {return _encounter_number;}
		void yourHero(string sentence);
		void combat();
		void victory_message();
		void loss_message();

};

class Hero : public Unit
{
	private:
		int _luck;
	public:
		Hero();
		int luck() {return _luck;}
		void victoryAward();
};

class Glad : public Unit
{
	public:
		Glad();
		int hitChance();
		void powerup(int value, int maxhp, int attack, int def);
};

class Animal : public Unit
{
	public:
		Animal();
};
