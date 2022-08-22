#include <iostream>
using namespace std;
class Car
{
public:
	Car(string com = "NoName", string mod = "NoName")
	{
		company = (com != " ") ? com : "NoNmame";
		model = (mod != " ") ? mod : "NoName";
		cout << "Автомобиль:" << endl << "company = " << company << endl 
			<< "model = " << model << endl;
	}
protected:
	string company;
	string model;
};

class PassengerCar :virtual public Car
{
public:
	PassengerCar(string com = "NoName", string mod = "NoName", double _clearence = 30.0) :Car(com, mod)
	{
		clearence = (_clearence > 0 && _clearence < 200) ? _clearence : 30.0;
		cout << "Пассажирский автомобиль:" << endl << "company = " << company << endl
			<< "model = " << model << endl
			<< "clearence = " << clearence << endl;
	}
protected:
	double clearence;
};


class Bus :virtual public Car
{
public:

	Bus(string com = "NoName", string mod = "NoName", int _numSeats = 30) :Car(com, mod)
	{
		numSeats = (_numSeats > 0) ? _numSeats : 30;
		cout << "Автобус:" << endl << "company = " << company << endl
			<< "model = " << model << endl
			<< "number of seatd = " << numSeats << endl;
	}
protected:
	int numSeats;
};

class Minivan :public PassengerCar, public Bus
{
public:
	Minivan(string com = "NoName", string mod = "NoName", double _clearence = 30.0, int _numSeats = 5) :PassengerCar(com, mod, _clearence), Bus(com, mod, _numSeats)
	{
		cout << "Минивэн:" << endl << "company = " << company << endl
			<< "model = " << model << endl
			<< "clearence = " << clearence << endl
			<< "number of seatd = " << numSeats << endl;
	}
};