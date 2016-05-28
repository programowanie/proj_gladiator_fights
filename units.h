#pragma once

#include <string>
#include <vector>

using namespace std;

class Unit
{
	public:
		static vector <string> names;
		static vector <string> animal_names;

		string _name;
		int _hp, totalHp;
		int _attackPower, _defencePower;
		static void init();

		int hp() {return _hp;}
		string name() {return _name;}
		int attackPower() {return _attackPower;}
		int defencePower() {return _defencePower;}
	
};

class Encounter
{
	private:
		int _encounter_number=1;
		
		void victory_message(string name);
		void loss_message(string hero, string enemy);

		double hittedSpotMultiplation();			//Wprowadziłem dodatkową funkcję która ciekawie wpływa na faktyczne wartości obrażeń.
													//Ta funkcja reprezentuje sytuację uderzeń krytycznych, np miecz może uderzyć w naramiennik i zadać mało obrażeń
													//ale także może uderzyć, np w krocze i zadać obrażenia krytyczne :P
	public:
		/*Encounter();*/

		int damage_received(int dmg, int armor);
		string nameOfHero;

		int encounter_number();

		void yourHero(string sentence);
		
		void combatLoop(int heroHp, int heroDmg, int heroDef, int enemyHp, int enemyDmg, int enemyDef);

		bool areYouDead(int value);

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
class Centurion : public Unit
{
	public:
		void enrage(int atk, int def);
		Centurion();
		int hitChance();
};
