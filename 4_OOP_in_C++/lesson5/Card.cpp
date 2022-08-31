#include <iostream>
#include "Card.h"
using namespace std;

void Card::Flip()
{
	if (position == true)
		position = false;
	else
		position = true;
}

int Card::GetValue()
{
	return _num;
}