#include <iostream>
#include "Card.h";

Card::Card(Ranks rank, Suits suit)
	: m_cardRank{ rank }, m_cardSuit{ suit }
{
}

void Card::printCard() const
{
	switch (m_cardRank)
	{
	case Ranks::ranks2:
		std::cout << '2';
		break;
	case Ranks::ranks3:
		std::cout << '3';
		break;
	case Ranks::ranks4:
		std::cout << '4';
		break;
	case Ranks::ranks5:
		std::cout << '5';
		break;
	case Ranks::ranks6:
		std::cout << '6';
		break;
	case Ranks::ranks7:
		std::cout << '7';
		break;
	case Ranks::ranks8:
		std::cout << '8';
		break;
	case Ranks::ranks9:
		std::cout << '9';
		break;
	case Ranks::ranks10:
		std::cout << "10";
		break;
	case Ranks::jack:
		std::cout << 'J';
		break;
	case Ranks::queen:
		std::cout << 'Q';
		break;
	case Ranks::king:
		std::cout << 'K';
		break;
	case Ranks::ace:
		std::cout << 'A';
		break;

	default:
		std::cout << '?';
		break;
	}

	switch (m_cardSuit)
	{
	case Suits::clubs:
		std::cout << 'C';
		break;
	case Suits::diamonds:
		std::cout << 'D';
		break;
	case Suits::hearths:
		std::cout << 'H';
		break;
	case Suits::spades:
		std::cout << 'S';
		break;

	default:
		std::cout << '?';
		break;
	}
}

int Card::getCardValue() const
{
	switch (m_cardRank)
	{
	case Ranks::ranks2: return 2;
	case Ranks::ranks3: return 3;
	case Ranks::ranks4: return 4;
	case Ranks::ranks5: return 5;
	case Ranks::ranks6: return 6;
	case Ranks::ranks7: return 7;
	case Ranks::ranks8: return 8;
	case Ranks::ranks9: return 9;
	case Ranks::ranks10: return 10;
	case Ranks::jack:
	case Ranks::queen:
	case Ranks::king: return 10;
	case Ranks::ace: return 11;

	default: return 0;
	}
}