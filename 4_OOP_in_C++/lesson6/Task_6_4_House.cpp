#include "GenericPlayer.cpp"
#include<iostream>
using namespace std;

class House :public GenericPlayer
{
public:
	virtual bool IsHitting() override
	{
		if (getValue() < 16)
		{
			Add();
		}
	}

	void FlipFirstCard()
	{
		hand[0]->Flip();
	}
};