#pragma once
#include "Hand.h"

class GenericPlayer :public Hand
{
public:
	friend ostream& operator<<(ostream&, GenericPlayer&);
	virtual bool IsHitting() = 0;
	bool IsBoosted();
	void Bust();

protected:
	std::string name;
};

ostream& operator<<(ostream& os, GenericPlayer& gp)
{
	os << gp.name << ": " << gp.getValue() << " - ";
	for (vector<int>::size_type i = 0; i != gp.hand.size(); i++)
	{
		if (i == gp.hand.size() - 1)
			os << *gp.hand[i];
		os << *gp.hand[i] << ", ";
	}
	return os;
}