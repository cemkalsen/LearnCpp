#include <iostream>
#include <cstdlib>
#include <string>

#include "Creature.h"
#include "Monster.h"
#include "Player.h"
#include "Potion.h"
#include "MyRandom.h"

int main()
{

	std::cout << "--------------------------\nWEEEELCOME TO OUR RPG GAME\nType(y) if you wanna see guides, other keys to not see:";


	char choice{};
	std::cin >> choice;

	if (choice == 'y')
	{
		std::cout << "\n\nYou start with 10 hp and 1 attack point.\nYou level up each time you kill an enemy and you gain an attack point.\n"
			<< "Somethimes you'll find a potion. These have 3 types: Health, Strength, Poison.\n"
			<< "You won't know what you drink untill you drink it.\n"
			<< "A Strenth potion gives you an attack point, a poison potion takes an hp.\n"
			<< "Small and medium health potions give you 2 hp, large potion gives you 5hp\n\n";
	}

	std::cout << "What is your name : ";
	std::string name;
    std::cin.ignore();
	std::getline(std::cin, name);

	Player myPlayer{ name };
	std::cout << "Hi " << name << ". The game is starting :) \n\n";

	while (!myPlayer.isDead() && !myPlayer.hasWon())
	{
		Monster newMonster = Monster::getRandomMonster();		
		myPlayer.fightMonster(newMonster);

	}

	if (myPlayer.isDead())
		std::cout << "You died at level " << myPlayer.getLevel() << " and with "
		<< myPlayer.getGold() << " gold\n" << "Too bad you can't take it with you.";
	else if (myPlayer.hasWon())
		std::cout << "CONGRATSSS YOU WINNNN";
	else
		std::cout << "WTF JUST HAPPENED?";

	std::cout << "\n\n\n\n";

	return 0;
}