#include "GenericPlayer.cpp"
#include <iostream>
using namespace std;

class Player :public GenericPlayer
{
public:
	virtual bool IsHitting() override
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

	void Win()
	{
		cout << "Игрок " << name << " выиграл" << endl;
	}

	void Lose()
	{
		cout << "Игрок " << name << " проиграл" << endl;
	}

	void Push()
	{
		cout << "Игрок " << name << " сыграл вничью" << endl;
	}
};