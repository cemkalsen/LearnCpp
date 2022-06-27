#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"

class Player
{
public:
	Player(bool isDealer);

	int  calculateDeckPoint();
	void takeTurn();
	void playHit();
	bool getStayStatus() { return m_didStay; }

private:

	bool m_isDealer{};
	bool m_didStay{ false };
	std::vector<Card> m_playerDeck{};
	static inline std::size_t m_iterator{ 0 };
};

#endif