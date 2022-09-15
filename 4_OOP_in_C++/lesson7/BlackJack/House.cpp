#include "House.h"
bool House::IsHitting()
{
	return(getValue() <= 16);
}

void House::FlipFirstCard()
{
	if (hand.empty())
	{
		cout << "No card !" << endl;
	}
	else
	{
		hand[0]->Flip();
	}
}
