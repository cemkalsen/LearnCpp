#include <iostream>
#include <random>
#include "Deck.h"

Deck::Deck()
{
	for (int i{ 0 }; i < 52; ++i)
	{

		m_decky[i].m_cardRank = static_cast<Card::Ranks>(i % static_cast<int>(Card::maxRanks));
		m_decky[i].m_cardSuit = static_cast<Card::Suits>(i % static_cast<int>(Card::maxSuits));
	}

	shuffle();
}

void Deck::print() const
{
	for (const Card& card : m_decky)
	{
		card.printCard();
		std::cout << ' ';
	}
	std::cout << '\n';
}

void Deck::shuffle()
{
	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::shuffle(m_decky.begin(), m_decky.end(), mt);
}