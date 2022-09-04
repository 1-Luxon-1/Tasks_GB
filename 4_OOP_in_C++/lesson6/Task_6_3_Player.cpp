#include "GenericPlayer.cpp"
#include <iostream>
using namespace std;

class Player :public GenericPlayer
{
public:
	virtual bool IsHitting() override
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

	void Win()
	{
		cout << "����� " << name << " �������" << endl;
	}

	void Lose()
	{
		cout << "����� " << name << " ��������" << endl;
	}

	void Push()
	{
		cout << "����� " << name << " ������ ������" << endl;
	}
};