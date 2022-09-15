#include "Player.h"

Player::Player() {}

Player::~Player() {}

Player::Player(const string& _name)
{
	name = _name;
}

bool Player::IsHitting()
{
	char s;
	cout << "Нужна ещё карта (y/n) ?: ";
	cin >> s;
	if (s == 'y')
	{
		return true;
	}
	return false;
}

void Player::Win()
{
	cout << "Игрок " << name << " выиграл" << endl;
}

void Player::Lose()
{
	cout << "Игрок " << name << " проиграл" << endl;
}

void Player::Push()
{
	cout << "Игрок " << name << " сыграл вничью" << endl;
}
