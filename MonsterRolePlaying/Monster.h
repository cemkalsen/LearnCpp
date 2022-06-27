#ifndef MONSTER_H
#define MONSTER_H

#include "Creature.h"
class Player;

class Monster : public Creature
{
public:
	enum Type
	{
		dragon,
		orc,
		slime,
		max_types,
	};

	Monster(Type monsterType);
	static Monster getRandomMonster();
	void attackPlayer(Player& p);

private:
	static const Creature& getDefaultCreature(Type type);
};

#endif