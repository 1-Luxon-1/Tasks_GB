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
	cout << "����� ��� ����� (y/n) ?: ";
	cin >> s;
	if (s == 'y')
	{
		return true;
	}
	return false;
}

void Player::Win()
{
	cout << "����� " << name << " �������" << endl;
}

void Player::Lose()
{
	cout << "����� " << name << " ��������" << endl;
}

void Player::Push()
{
	cout << "����� " << name << " ������ ������" << endl;
}
