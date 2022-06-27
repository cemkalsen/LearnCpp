#include <iostream>
#include <array>
#include <algorithm>
#include <random>
#include <ctime>
#include "Player.h"
#include "Deck.h"
#include "Card.h"

enum class WinState
{
	playerWon,
	dealerWon,
	tie,
};

void playBlackJack()
{
	Deck myDeck{};
	Player dealer(true);
	Player player(false);
	WinState whoWon{};

	std::cout << "WEEEELCOME TO OUR GAMEE BLACKJACK\n\n";

	while (!(dealer.getStayStatus() && player.getStayStatus()))
	{
		player.takeTurn();
		dealer.takeTurn();
	}

	std::cout << "THE GAME HAS FINISHED.\nLET ME CALCULATE SCORES\nAnd the winner isssss...\n";


	if (dealer.calculateDeckPoint() > 21 || player.calculateDeckPoint() > 21)
	{
		if (player.calculateDeckPoint() > 21 && dealer.calculateDeckPoint() <= 21)
			whoWon = WinState::dealerWon;
		else if (player.calculateDeckPoint() <= 21 && dealer.calculateDeckPoint() > 21)
			whoWon = WinState::playerWon;
		else if (player.calculateDeckPoint() > 21 && dealer.calculateDeckPoint() > 21)
			whoWon = WinState::tie;
	}

	else
	{
		if (player.calculateDeckPoint() > dealer.calculateDeckPoint())
			whoWon = WinState::playerWon;
		else if (player.calculateDeckPoint() < dealer.calculateDeckPoint())
			whoWon = WinState::dealerWon;
		else if (player.calculateDeckPoint() == dealer.calculateDeckPoint())
			whoWon = WinState::tie;
	}

	switch (whoWon)
	{
	case WinState::playerWon:
		std::cout << "PLAYEEEEEER\n";
		break;

	case WinState::dealerWon:
		std::cout << "DEALEEEEER\n";
		break;

	case WinState::tie:
		std::cout << "BOOORING ITS A TIE\n";
		break;

	default:
		std::cout << "UNDEFINED\n";
		break;
	}

	std::cout << "Player's score was: " << player.calculateDeckPoint() << '\n'
		<< "Dealer's score was: " << dealer.calculateDeckPoint() << "\n\n";

};

int main()
{
	playBlackJack();

	return 0;
}