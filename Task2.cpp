#include <iostream>
#include<locale>
using namespace std;

// 2,3,4 задача
enum CrossZero { Cross, Zero, Empty };
struct PlaneGame
{
    CrossZero Field[3][3] = { {Cross,Empty,Empty},{Empty,Cross,Empty},{Empty,Empty,Zero} }; // поле
    char PlayerCross[15];                                                                   // имена игроков
    char PlayerZero[15];
    unsigned short flag : 1;                                                                // определяет, кто ходит (0 - первый игрок, 1 - второй)
    bool Game = true;                                                                       // переменная, определяющая закончилась ли игра
};

// 5 задача
struct MyVariant
{
    union MyData
    {
        int i;
        float f;
        char c;
    }Dat;
    unsigned short isInt : 1;
    unsigned short isFloat : 1;
    unsigned short isChar : 1;
};


int main()
{
    setlocale(LC_ALL, "RUSSIAN");

    // 1 задача
    short ShortVar = 1;
    char CharVar = '2';
    int IntVar = 333;
    long long LongVar = 4444;
    float FloatVar = 555.55f;
    double DoubleVar = 6666.6666;
    bool BoolVar = true;
    cout << "Переменная типа short: " << ShortVar << endl;
    cout << "Переменная типа char: " << CharVar << endl;
    cout << "Переменная типа int: " << IntVar << endl;
    cout << "Переменная типа long long: " << LongVar << endl;
    cout << "Переменная типа double: " << DoubleVar << endl;
    cout << "Переменная типа bool: " << boolalpha << BoolVar << "\n\n" << endl;



    // продолжение 5 задачи
    MyVariant var;
    var.Dat.i = 5;
    var.isInt = 1;
    var.isFloat = 0;
    var.isChar = 0;
    cout << "Значение переменной равно " << var.Dat.i << " типа int" << endl;

    var.Dat.f = 5.5;
    var.isInt = 0;
    var.isFloat = 1;
    cout << "Значение переменной равно " << var.Dat.f << " типа float" << endl;

    var.Dat.c = 'a';
    var.isFloat = 0;
    var.isChar = 1;
    cout << "Значение переменной равно " << var.Dat.c << " типа char" << endl;
    return 0;
}