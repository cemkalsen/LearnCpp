#ifndef DECK_H
#define DECK_H

#include <array>
#include "Card.h";

class Deck
{
public:
	Deck();

	void print() const;
	void shuffle();
	
	static std::array<Card, 52> getDeck() { return m_decky; }

private:
	static inline std::array<Card, 52> m_decky{};
};


#endif