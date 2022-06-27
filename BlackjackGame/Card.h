#ifndef  CARD_H
#define  CARD_H

class Card
{
public:
	enum Ranks
	{
		ranks2,
		ranks3,
		ranks4,
		ranks5,
		ranks6,
		ranks7,
		ranks8,
		ranks9,
		ranks10,
		jack,
		queen,
		king,
		ace,
		maxRanks,
	};

	enum Suits
	{
		clubs,
		diamonds,
		hearths,
		spades,
		maxSuits,
	};

	Card() = default;
	Card(Ranks rank, Suits suit);

	void  printCard()    const;
	int   getCardValue() const;
	Ranks getRank()      const { return m_cardRank; }
	Suits getSuit()      const { return m_cardSuit; }

	friend class Deck;

private:

	Ranks m_cardRank{};
	Suits  m_cardSuit{};
};


#endif