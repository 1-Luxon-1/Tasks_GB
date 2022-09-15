#pragma once
#include "Card.h"
#include <vector>

class Hand :public Card
{
public:
	Hand();
	~Hand();
	void Add(Card* newCard);
	void Clear();
	int getValue();
protected:
	vector<Card*> hand;
};
