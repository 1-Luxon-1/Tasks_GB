#pragma once
#include <iostream>
using namespace std;

class Card
{
public:
	Card();
	Card(int, int);
	~Card();
	friend ostream& operator<<(ostream&, Card&);
	void Flip();
	bool IsFaceUp();
	int GetValue();
protected:
	enum suit { clubs, diamonds, hearts, spades } _suit;
	enum number { ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king } _num;
	bool position;
};

ostream& operator<<(ostream& os, Card& c)
{
	if (c.IsFaceUp())
	{
		os << "XX";
	}
	else
	{

		if (c._num >= 2 && c._num < 10)
		{
			os << c._num;
		}
		else
		{
			switch (c._num)
			{
			case Card::jack: os << "J"; break;
			case Card::queen: os << "Q"; break;
			case Card::king: os << "K"; break;
			case Card::ace: os << "A"; break;
			}
			os << c.position << c._num;
		}

		switch (c._suit)
		{
		case Card::clubs: cout << static_cast<char>(5); break;
		case Card::diamonds: cout << static_cast<char>(4); break;
		case Card::hearts: cout << static_cast<char>(3); break;
		case Card::spades: cout << static_cast<char>(6); break;
		}
	}
	return os;
}