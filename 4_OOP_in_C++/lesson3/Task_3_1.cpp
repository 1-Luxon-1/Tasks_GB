#include <iostream>
#include <math.h>
using namespace std;

class Figure
{
public:
	Figure(int _numAngle = 0)
	{
		numAngle = (_numAngle > 2) ? _numAngle : 0;
	}
	virtual double area() = 0;
protected:
	int numAngle;
};

class Parallelogram:public Figure
{
public:
	Parallelogram(double side1 = 4.0, double side2 = 13.0, double _angle1 = 30.0, double _angle2 = 150.0) :Figure(4)
	{
		sideLength1 = (side1 > 0) ? side1 : 4.0;
		sideLength2 = (side2 > 0) ? side2 : 13.0;
		angle1 = (_angle1 > 0 && _angle1 < 180) ? _angle1 : 30.0;
		angle2 = (_angle2 > 0 && _angle2 < 180) ? _angle2 : 150.0;

		if (angle1 + angle2 != 180)
		{
			sideLength1 = 4.0;
			sideLength2 = 13.0;
			angle1 = 30;
			angle2 = 150;
		}

	}

	virtual double area() override
	{
		return (sideLength1 * sideLength2 * sin(angle1 * 3.14159265 / 180));
	}

protected:
	double sideLength1;
	double sideLength2;
	double angle1;
	double angle2;

};

class Circle :public Figure
{
public:
	Circle(double _radius = 5.0) :Figure()
	{
		radius = (_radius > 0) ? _radius : 5.0;
	}

	virtual double area() override
	{
		return (2 * 3.14 * radius);
	}
private:
	double radius;
};

class Rectangle :public Parallelogram
{
public:
	Rectangle(double side1 = 5.0, double side2 = 8.0) :Parallelogram(side1, side2, 90, 90)
	{
		
	}
	virtual double area() override
	{
		return (sideLength1 * sideLength2);
	}
};

class Square :public Parallelogram
{
public:
	Square(double side = 5.0):Parallelogram(side,side,90,90){}
	
	virtual double area() override
	{
		return(sideLength1 * sideLength1);
	}
};

class Rhombus :public Parallelogram
{
public:
	Rhombus(double side = 5.0, double _angle1 = 30, double _angle2 = 150) :Parallelogram(side, side, _angle1, _angle2)
	{	}
	virtual double area() override
	{
		return (Parallelogram::sideLength1 * Parallelogram::sideLength1 * sin(Parallelogram::angle1  * 3.14159265 / 180));
	}
};