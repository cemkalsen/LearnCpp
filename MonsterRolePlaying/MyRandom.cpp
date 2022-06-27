#include "MyRandom.h"

std::random_device MyRandom::rd{};
std::seed_seq MyRandom::seq{ rd(),rd() ,rd() ,rd(),rd(),rd(),rd(),rd() };
std::mt19937 MyRandom::mt{ seq };

bool MyRandom::flipCoin()
{
	std::uniform_int_distribution coin(0, 1);
	if (coin(mt))
		return true;
	else
		return false;
}

bool MyRandom::thirtyPercent()
{
	std::uniform_int_distribution percent(1, 10);
	if (percent(mt) <= 3)
		return true;
	else
		return false;
}