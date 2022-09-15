#pragma once
#include "GenericPlayer.h"
class Player :public GenericPlayer
{
public:
	Player();
	Player(const string& name = "");
	~Player();

	virtual bool IsHitting() override;

	void Win();

	void Lose();

	void Push();
};
