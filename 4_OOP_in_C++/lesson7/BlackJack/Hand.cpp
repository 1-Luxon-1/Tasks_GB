#include "Hand.h"

Hand::Hand()
{}

Hand::~Hand()
{}

void Hand::Add(Card* newCard)
{
	hand.push_back(newCard);
}

void Hand::Clear()
{
	hand.clear();
}

int Hand::getValue()
{
	int sumAce = 0;
	int sum = 0;
	for (size_t i = 0; i < hand.size(); i++)
	{
		if ((hand[i]->GetValue()) == 1)
		{
			sumAce++;
			sum += hand[i]->GetValue();
		}
		else
		{
			if ((hand[i]->GetValue() == jack) || (hand[i]->GetValue() == queen) || (hand[i]->GetValue() == king))
				sum += 0;
			else
				sum += hand[i]->GetValue();
		}
	}
	if (sum <= 11 && sumAce > 0)
	{
		sum += 10;
	}
	return sum;
}
