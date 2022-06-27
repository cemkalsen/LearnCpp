#ifndef PLAYER_H
#define PLAYER_H

#include <string_view>

#include "Creature.h"
#include "MyRandom.h"
#include "Monster.h"
#include "Potion.h"

class Player : public Creature
{
public:

	Player(const std::string_view name);

	const int& getLevel() { return m_level; }

	void levelUp();
	bool hasWon();

	void fightMonster(Monster& monster);
	void attackMonster(Monster& monster);
	void drinkPotion(Potion& potion);;

private:
	int m_level{ 1 };
};

#endif