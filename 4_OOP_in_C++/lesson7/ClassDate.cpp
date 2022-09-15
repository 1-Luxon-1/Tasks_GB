#include "ClassDate.h"


Date::Date()
{
	day = 1;
	month = 1;
	year = 2000;
}

Date::Date(size_t d, size_t m, size_t y)
{
	day = d;
	month = m;
	year = y;
}

void Date::setDay(size_t d)
{
	day = d;
}

void Date::setMonth(size_t m)
{
	month = m;
}

void Date::setYear(size_t y)
{
	year = y;
}

size_t Date::getDay()
{
	return day;
}

size_t Date::getMonth()
{
	return month;
}

size_t Date::getYear()
{
	return year;
}

ostream& operator<< (ostream& out, const Date& dat)
{
	out << dat.day << ':' << dat.month << ':' << dat.year;
	return out;
}
