#include <iostream>
using namespace std;
class Ex
{
public:
	Ex(double _x):x(_x){}
	double get()
	{
		return x;
	}
protected:
	double x;
};

class Bar
{
public:
	Bar():y(0.0){}
	void set(double a)
	{
		try
		{
			if ((y + a) > 100) throw Ex(a * y);
			else
			{
				y = a;
			}
		}
		catch (...)
		{
			throw;
			cout << "a+y > 100" << endl;
		}
	}

	double get()
	{
		return y;
	}
private:
	double y;
};