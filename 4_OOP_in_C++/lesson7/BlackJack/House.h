#pragma once
#include "GenericPlayer.h"
class House :public GenericPlayer
{
public:
	virtual bool IsHitting() override;

	void FlipFirstCard();
};
