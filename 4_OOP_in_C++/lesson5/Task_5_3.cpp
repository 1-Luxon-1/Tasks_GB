#include "Task_5_2.cpp"
#include<iostream>
using namespace std;



template<typename T>
class StringValuePair :public Pair2<string, T>
{
public:

    StringValuePair(string _str, T _num) :Pair2<string, T>(_str, _num) {}

    string first()
    {
        return str;
    }

    T second()
    {
        return num;
    }
private:
    string str;
    T num;
};