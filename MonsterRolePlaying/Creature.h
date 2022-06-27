#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <string_view>

class Creature
{
public:
	Creature(const std::string_view name, char symbol, int hp, int ap, int gold)
		: m_name{ name }, m_symbol{ symbol }, m_hp{ hp }, m_ap{ ap }, m_gold{ gold }
	{

	}

	const std::string_view getName() const { return m_name; }
	const char getSymbol() const { return m_symbol; }
	const int getHp()      const { return m_hp; }
	const int getAp()      const { return m_ap; }
	const int getGold()    const { return m_gold; }

	void reduceHealth(int amount) { m_hp -= amount; }
	bool isDead() { return (m_hp <= 0); }
	void addGold(int amount) { m_gold += amount; }

protected:

	std::string m_name{};
	char m_symbol;
	int m_hp;
	int m_ap;
	int m_gold;
};

#endif