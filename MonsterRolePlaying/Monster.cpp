#include <random>
#include <array>
#include <iostream>
#include "Monster.h"
#include "Player.h"

Monster::Monster(Type monsterType)
	:Creature{ getDefaultCreature(monsterType) }
{
}

Monster Monster::getRandomMonster()
{
	static std::random_device rd;
	static std::seed_seq seq{ rd(),rd() ,rd() ,rd(),rd(),rd(),rd(),rd() };
	static std::mt19937 mt{ seq };
	std::uniform_int_distribution die6{ 0, static_cast<int>(Type::max_types) - 1 };

	return Monster{ static_cast<Type>(die6(mt)) };
}

void Monster::attackPlayer(Player& player)
{
	if (isDead())
		return;

	player.reduceHealth(m_ap);
	std::cout << "The " << getName() << " hit you " << m_ap << " damage.\n";
}

const Creature& Monster::getDefaultCreature(Type type)
{
	static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
	  { { "dragon", 'D', 20, 4, 100 },
		{ "orc", 'o', 4, 2, 25 },
		{ "slime", 's', 1, 1, 10 } }
	};

	return monsterData.at(static_cast<std::size_t>(type));
}