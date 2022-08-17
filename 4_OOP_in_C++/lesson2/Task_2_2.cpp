#include <iostream>
using namespace std;

class Fruit
{
public:
	Fruit(string _name = "noName", string _color = "colorless")
	{
		name = (_name != " ") ? _name : "noName";
		color = (_color != " ") ? _color : "colorless";
	}
protected:
	string name;
	string color;
};

class Apple:public Fruit
{
public:
	Apple(string _color="green") :Fruit("apple", _color){}

	string getName()
	{
		return name;
	}

	string getColor()
	{
		return color;
	}
};

class Banana :public Fruit
{
public:
	Banana():Fruit("banana", "yellow"){}

	string getName()
	{
		return name;
	}

	string getColor()
	{
		return color;
	}
};

class GrannySmith:public Apple
{
public:
	GrannySmith() :Apple(){}
	string getName()
	{
		string _name = "Granny Smith ";
		_name += Apple::getName();
		return _name;
	}
};
