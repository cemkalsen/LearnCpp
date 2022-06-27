#ifndef MYRANDOM_H
#define MYRANDOM_H
#include <random>


class MyRandom
{
public:
	static bool flipCoin();
	static bool thirtyPercent();


private:
	static std::random_device rd;
	static std::seed_seq seq;
	static std::mt19937 mt;
};

#endif