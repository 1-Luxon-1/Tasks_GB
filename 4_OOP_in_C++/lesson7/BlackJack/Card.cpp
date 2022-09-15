#include "Card.h"
Card::Card() {}

Card::~Card() {}

Card::Card(int n, int s)
{
	_num = static_cast<Card::number>(n);
	_suit = static_cast<Card::suit>(s);
}
void Card::Flip()
{
	if (position == true)
		position = false;
	else
		position = true;
}

bool Card::IsFaceUp()
{
	return position;
}

int Card::GetValue()
{
	return _num;
}
