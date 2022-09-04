#include <iostream>
#include "Hand.h"
using namespace std;

class GenericPlayer :public Hand
{
public:

	virtual bool IsHitting() = 0;

	bool isBoosted()
	{
		if (Hand::GetValue() > 21)
			return true;
		else
			return false;
	}

	void Bust()
	{
		cout << name << " перебор !" << endl;
	}

protected:
	string name;
};