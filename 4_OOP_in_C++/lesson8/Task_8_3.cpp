#include <iostream>
using namespace std;


class OffTheField
{
public:
	OffTheField(string str, int x, int y, char dir)
	{
		err = str;
		lastX = x;
		lastY = y;
		lastDir = dir;
	}
	void getError()
	{
		cerr << err << endl;
	}
	void getInfo()
	{
		cout << "Положение робота: x = " << lastX << ", y = " << lastY << ", направление = " << lastDir << endl;
	}
private:
	string err;
	int lastX;
	int lastY;
	char lastDir;
};

class IllegalCommand
{
public:
	IllegalCommand(string str, int x, int y, char dir)
	{
		err = str;
		lastX = x;
		lastY = y;
		lastDir = dir;
	}
	void getError()
	{
		cerr << err << endl;
	}
	void getInfo()
	{
		cout << "Положение робота: x = " << lastX << ", y = " << lastY << ", направление = " << lastDir << endl;
	}
private:
	string err;
	int lastX;
	int lastY;
	char lastDir;
};


class Robot
{
public:
	Robot()
	{
		Field = new char* [10];
		for (int i = 0; i < 10; i++)
		{
			Field[i] = new char[10];
		}
		xCoord = 4;
		yCoord = 4;
	}

	~Robot()
	{
		for (int i = 0; i < 10; i++)
		{
			delete[] Field[i];
		}
		delete[] Field;
	}

	void getField()
	{
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				if (i == yCoord && j == xCoord)
					cout << "x ";
				else
					cout << "* ";
			}
			cout << endl;
		}
	}
	void moving(char);
protected:
	char** Field;
	int xCoord;
	int yCoord;
};


void Robot::moving(char direction)
{
	try
	{
		if (direction != 'l' && direction != 'r' && direction != 'f' && direction != 'b') throw IllegalCommand("Несуществующее направление !!", xCoord, yCoord, direction);
		switch (direction)
		{
		case 'l': if (xCoord - 1 < 0) throw OffTheField("Вы вышли за границы поля !!", xCoord, yCoord, direction);
				else
			xCoord--;
			break;
		case 'r': if (xCoord + 1 >= 10) throw OffTheField("Вы вышли за границы поля !!", xCoord, yCoord, direction);
				else
			xCoord++;
			break;
		case 'f': if (yCoord - 1 < 0) throw OffTheField("Вы вышли за границы поля !!", xCoord, yCoord, direction);
				else
			yCoord--;
			break;
		case 'b': if (yCoord + 1 >= 10) throw OffTheField("Вы вышли за границы поля !!", xCoord, yCoord, direction);
				else
			yCoord++;
			break;

		}
	}
	catch (IllegalCommand& ic)
	{
		ic.getError();
		ic.getInfo();
	}
	catch (OffTheField& of)
	{
		of.getError();
		of.getInfo();
	}
}
