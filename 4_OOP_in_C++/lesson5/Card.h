#pragma once
class Card
{
public:
	void Flip();
	int GetValue();

protected:
	enum suit { clubs, diamonds, hearts, spades } _suit;
	enum number { two = 2, three, four, five, six, seven, eight, nine, ten, jack = 10, queen = 10, king = 10, ace = 1 } _num;
	bool position;
};