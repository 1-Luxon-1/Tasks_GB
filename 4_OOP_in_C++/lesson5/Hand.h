#pragma once
#include "Card.h"
#include <vector>
#include<iostream>
using namespace std;

class Hand :public Card
{
public:
	void Add(Card* newCard);
	void Clear();
	int getValue();
protected:
	vector<Card*> hand;
};