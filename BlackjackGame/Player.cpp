#include<iostream>
#include "Player.h"
#include "Deck.h"

Player::Player(bool isDealer) : m_isDealer{isDealer}
{
	if (isDealer)
	{
		m_playerDeck.push_back(Deck::getDeck()[m_iterator++]);
	}
	else
	{
		m_playerDeck.push_back(Deck::getDeck()[m_iterator++]);
	}
}

int Player::calculateDeckPoint()
{
	int totalPoints{ 0 };
	int aceCounter{ 0 };

	for (Card playerCard : m_playerDeck)
	{
		totalPoints += playerCard.getCardValue();
		if (playerCard.getRank() == Card::Ranks::ace)
		{
			++aceCounter;
		}
	}

	while (aceCounter != 0 && totalPoints > 21)
	{
		totalPoints -= 10;
		--aceCounter;
	}

	return totalPoints;
}

void Player::takeTurn()
{
	if (m_isDealer)
	{
		std::cout << "Its dealers turn.\n";

		if (calculateDeckPoint() <= 17)
		{
			m_playerDeck.push_back(Deck::getDeck()[m_iterator++]);
			std::cout << "Dealer has chosen hit.\n\n";
		}
		else
		{
			std::cout << "Dealer has chosen stay.\n\n";
			m_didStay = true;
		}
	}
	else
	{
		std::cout << "You have " << calculateDeckPoint() << " points.\n"
			<< "Type \"h\" to hit or \"s\" to stay: ";
		char choice{};
		std::cin >> choice;

		if (choice == 'h')
			playHit();
		if (choice == 's')
		{
			std::cout << "You have chosen to stay\n\n";
			m_didStay = true;
		}
	}
}

void Player::playHit()
{
	m_playerDeck.push_back(Deck::getDeck()[m_iterator++]);

	std::cout << "Now you have " << calculateDeckPoint() << " points.\n\n";
}