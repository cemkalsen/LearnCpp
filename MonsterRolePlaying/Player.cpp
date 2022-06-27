#include <iostream>
#include "Player.h"

Player::Player(const std::string_view name)
	: Creature{ name, '@', 10,1,0 }
{
}

void Player::fightMonster(Monster& monster)
{
	std::cout << "\nYou have encountered a " << monster.getName() << " that has "
		<< monster.getHp() << " hp and " << monster.getAp() << " ap.\n";

	while (!isDead() && !monster.isDead())
	{
		std::cout << "(r)un or (f)ight:";

		char choice{};
		std::cin >> choice;

		if (choice == 'r')
		{
			if (MyRandom::flipCoin())
			{
				std::cout << "You failed to flee\n";
				choice = 'b';
			}
			else
			{
				std::cout << "You succesfully fled.\n";
				return;
			}
		}
		if (choice == 'f')
		{
			attackMonster(monster);
			monster.attackPlayer(*this);
		}
		if (choice == 'b')
		{
			monster.attackPlayer(*this);

		}
	}
}

void Player::attackMonster(Monster& monster)
{
	monster.reduceHealth(m_ap);
	std::cout << "You hit the " << monster.getName() << ' ' << m_ap << " damage.\n";

	if (monster.isDead())
	{
		levelUp();
		addGold(monster.getGold());
		std::cout << "You killed it!\n"
			<< "You are now level " << m_level << '\n'
			<< "Remaining hp: " << m_hp << '\n'
			<< "You have found " << monster.getGold() << " gold.\n";

		if (MyRandom::thirtyPercent())
		{
			Potion myPotion = Potion::getRandomPotion();
			std::cout << "You found a mythical potion! "
				<< "Do you want to drink it? (y/n): ";

			char choice{};
			std::cin >> choice;

			if (choice == 'y')
				drinkPotion(myPotion);
		}

	}
}

void Player::drinkPotion(Potion& potion)
{
	std::cout << "You drank a " << potion.getSizeStr() << " potion of " << potion.getTypeStr()
		<< '\n';

	switch (potion.getType())
	{
	case Potion::Type::health:

		switch (potion.getSize())
		{
		case Potion::Size::small:
		case Potion::Size::medium:  m_hp += 2; break;
		case Potion::Size::large:   m_hp += 5; break;
		default:         break;
		}


	case Potion::Type::strength:   ++m_ap; return;
	case Potion::Type::poison:     --m_hp; return;
	default:                       return;
	}
}

void Player::levelUp() { ++m_level; ++m_ap; }
bool Player::hasWon() { return (m_level >= 20); }