#include <iostream>
#include <memory>
#include "ClassDate.h"

////////// Task2 ////////////
shared_ptr<Date>& compDate(shared_ptr<Date>& d1, shared_ptr<Date>& d2)
{
    if (d1->getYear() > d2->getYear())
    {
        return d1;
    }
    else
        if (d1->getYear() < d2->getYear())
            return d2;
    if (d1->getMonth() > d2->getMonth())
    {
        return d1;
    }
    else
        if (d1->getMonth() < d2->getMonth())
            return d2;
    if (d1->getDay() > d2->getDay())
    {
        return d1;
    }
    else
        if (d1->getDay() < d2->getDay())
            return d1;
}

void swapDate(shared_ptr<Date>& d1, shared_ptr<Date>& d2)
{
    size_t day;
    size_t month;
    size_t year;
    day = d1->getDay();
    d1->setDay(d2->getDay());
    d2->setDay(day);

    month = d1->getMonth();
    d1->setMonth(d2->getMonth());
    d2->setMonth(month);

    year = d1->getYear();
    d1->setYear(d2->getYear());
    d2->setYear(year);
}
/////////////////////////////

int main()
{
    /////////////////////////
    //////// Task 1 /////////
    /////////////////////////

    shared_ptr<Date> today(new Date);
    shared_ptr<Date> date(new Date);
    today->setDay(8);
    today->setMonth(9);
    today->setYear(2022);
    cout << "today: " << *today << endl;
    date = today;
    cout << today.get() << "  " << date.get() << endl;
    cout << "today: " << *today << "  " << "date: " << *date << endl;

    /////////////////////////
    //////// Task 2 /////////
    /////////////////////////
    shared_ptr<Date> date1(new Date(1, 2, 2003));
    shared_ptr<Date> date2(new Date(5, 5, 2020));
    shared_ptr<Date> res(new Date);
    res = compDate(date1, date2);
    cout << *date1 << "  " << *date2 << endl;
    cout << endl << *res << endl;

    swapDate(date1, date2);
    cout << *date1 << "  " << *date2 << endl;


    /////////////////////////
    //////// Task 3 /////////
    /////////////////////////

    return 0;
}
