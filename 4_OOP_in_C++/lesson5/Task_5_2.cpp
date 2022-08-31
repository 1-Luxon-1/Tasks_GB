#include<iostream>
using namespace std;

template<typename T1, typename T2>
class Pair2
{
public:
    Pair2(T1 _num1, T2 _num2) :num1(_num1), num2(_num2) {}

    T1 first()
    {
        return num1;
    }

    T2 second()
    {
        return num2;
    }
protected:
    T1 num1;
    T2 num2;
};


template<class T>
class Pair2<string, T>
{
public:
    Pair2(string _num1, T _num2) :num1(_num1), num2(_num2) {}

    string first()
    {
        return num1;
    }

    T second()
    {
        return num2;
    }
protected:
   string num1;
    T num2;
};