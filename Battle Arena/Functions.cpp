#include <iostream>
#include <string>
#include <ctime>
#include "Classes.h"
#include <thread>
hero Ezio{ "Ezio Auditore",50,20,7,8 };
hero Edward{ "Edward James Kenway", 50,25,7,6 };
hero Altaire{ "Altaire Ibn-La'Ahad",50,20,5,9 };

hero Shay{ "Shay Cormac The Rogue",50,25,7,7 };
hero Haythem{ "Grand Master Haythem Kenway",50,25,8,5 };
hero Cesare{ "Lord Cesare Borgia",50,20,5,9 };

hero Assassins[3]{ Ezio,Edward,Altaire };
hero Templars[3]{ Shay,Haythem,Cesare };
int x, y, temp;
int assassinsAlive = 3;
int templarsAlive = 3;
int templarTarget = 0;
int assassinTarget = 0;
bool assassinsRemaining(int assassins) {
	if (assassins > 0) {
		return true;
	}
	else {
		return false;
	}
}
bool templarsRemaining(int templars) {
	if (templars > 0) {
		return true;
	}
	else {
		return false;
	}
}

void gameLoop() {
	while (assassinsAlive && templarsAlive != 0) {
		
			if (assassinsRemaining(assassinsAlive))
			{
				for (size_t i = 0; i < assassinsAlive; i++)
				{

					if (templarsAlive > 0) {
						cout << "++++ASSASSIN'S TURN++++" << endl;
						this_thread::sleep_for(std::chrono::seconds(1));
						cout << Assassins[i].name << " Attacks for " << Assassins[i].attack << " damage. " << endl;
						cout << " " << endl;
						this_thread::sleep_for(std::chrono::seconds(1));
						int damage = Assassins[i].attack;
						Templars[templarTarget].takeDamage(damage);
						if (!Templars[templarTarget].hasHealth())
						{
							--templarsAlive;
							++templarTarget;
							cout << "The Templar "<< Templars[templarTarget].name << " falls" << endl;
							cout << " " << endl;
							cout << "There is " << templarsAlive << " Templars left" << endl;
							cout << " " << endl;							
							this_thread::sleep_for(std::chrono::seconds(1));
							
						}
					
					}
				}
			}
			if (templarsRemaining(templarsAlive))
			{
				for (size_t i = 0; i < templarsAlive; i++)
				{
					if (assassinsAlive > 0) {
						cout << "++++TEMPLAR'S TURN++++" << endl;
						this_thread::sleep_for(std::chrono::seconds(1));
						cout << Templars[i].name << " Attacks for " << Templars[i].attack << " damage." << endl;
						cout << " " << endl;
						this_thread::sleep_for(std::chrono::seconds(1));
						int damage = Templars[i].attack;
						Assassins[assassinTarget].takeDamage(damage);
						if (!Assassins[assassinTarget].hasHealth())
						{
							--assassinsAlive;
							++assassinTarget;
							cout << "The Assasin "<< Assassins[assassinTarget].name <<" bested" << endl;
							cout << "There is " << assassinsAlive << " Assassin's left." << endl;
							cout << " " << endl;
							this_thread::sleep_for(std::chrono::seconds(1));
							
						}
					}
				}
			}


		
	}
	if (assassinsAlive == 0) {
		cout << "The battle is over." << endl;
		cout << "The Templars have won." << endl;
	}
	else {
		cout << "The battle is over." << endl;
		cout << "The Assassins have won." << endl;
	}



}
void attackrand() {
	for (size_t i = 0; i < 3; i++)
	{
		srand((int)time(0));
		Assassins[i].attack = Assassins->attack + rand() % Assassins->strength;
		Templars[i].attack = Templars->attack + rand() % Templars->strength;
	}
}
void healthrand() {
	for (size_t i = 0; i < 3; i++)
	{
		srand((int)time(0));
		Assassins[i].health = Assassins->health + rand() % Assassins->endurance;
		Templars[i].health = Templars->health + rand() % Templars->endurance;
	}


}
void intro() {
	cout << "ASSASSIN'S VS TEMPLARS" << endl;
	cout << "OUR ASSASSINS ARE" << endl;
	cout << Assassins[0].name << endl;
	cout << Assassins[1].name << endl;
	cout << Assassins[2].name << endl;
	cout << "AND OUR TEMPLARS ARE" << endl;
	cout << Templars[0].name << endl;
	cout << Templars[1].name << endl;
	cout << Templars[2].name << endl;
}
void sorting() {


	for (int i = 0; i<3; i++)
	{
		for (y = i + 1; y<3; y++)
		{
			if (Assassins[i].health>Assassins[y].health)
			{
				temp = Assassins[i].health;
				Assassins[i].health = Assassins[y].health;
				Assassins[y].health = temp;
			}
		}
	}
	for (int i = 0; i<3; i++)
	{
		for (y = i + 1; y<3; y++)
		{
			if (Templars[i].health>Templars[y].health)
			{
				temp = Templars[i].health;
				Templars[i].health = Templars[y].health;
				Templars[y].health = temp;
			}
		}
	}
}