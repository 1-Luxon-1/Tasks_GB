#include "Deck.h"
#include <algorithm>

Deck::Deck()
{
	hand.reserve(52);
	Populate();
}

Deck::~Deck()
{ }

void Deck::Populate()
{
	Clear();
	for (int s = Card::clubs; s <= Card::spades; s++)
	{
		for (int n = Card::ace; n <= Card::king; n++)
		{
			Add(new Card(static_cast<Card::number>(n), static_cast<Card::suit>(s)));
		}
	}
}

void Deck::Shuffle()
{
	random_shuffle(hand.begin(), hand.end());
}

void Deck::Deal(Hand& aHand)
{
	if (!hand.empty())
	{
		aHand.Add(hand.back());
		hand.pop_back();
	}
	else
	{
		cout << "Out of cards. Unable to deal.";
	}

}

void Deck::AdditionalCards(GenericPlayer& _GenericPlayer)
{
	while (!(_GenericPlayer.IsBoosted()) && _GenericPlayer.IsHitting())
	{
		Deal(_GenericPlayer);
		cout << _GenericPlayer << endl;
		if (_GenericPlayer.IsBoosted())
		{
			_GenericPlayer.Bust();
		}
	}
}
