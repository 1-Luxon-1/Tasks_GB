#include<iostream>
#include <vector>
#include "Hand.h"
using namespace std;

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
		if ((hand[i]->GetValue()) == ace)
		{
			sumAce++;
			sum += _num;
		}
		else
		{
			sum += _num;
		}
	}
	if (sum <= 11 && sumAce > 0)
	{
		sum += 10;
	}
	return sum;
}
