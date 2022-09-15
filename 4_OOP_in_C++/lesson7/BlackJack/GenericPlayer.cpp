#include "GenericPlayer.h"

bool GenericPlayer::IsBoosted()
{
	if (Hand::GetValue() > 21)
		return true;
	else
		return false;
}

void GenericPlayer::Bust()
{
	cout << name << " перебор !" << endl;
}

