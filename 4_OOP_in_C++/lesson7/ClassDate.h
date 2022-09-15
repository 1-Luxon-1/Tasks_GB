#pragma once
#include<iostream>
using namespace std;
class Date
{
public:
	friend ostream& operator<<(ostream&, const Date&);
	Date();
	Date(size_t d, size_t m, size_t y);
	void setDay(size_t d);
	void setMonth(size_t m);
	void setYear(size_t y);
	size_t getDay();
	size_t getMonth();
	size_t getYear();

private:
	size_t day;
	size_t month;
	size_t year;
};