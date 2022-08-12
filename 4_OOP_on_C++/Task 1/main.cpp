#include<iostream>
#include "Task_1_1.cpp"
#include "Task_1_2.cpp"
#include "Task_1_3.cpp"
using namespace std;
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    /////////////////////////////////////////////////////
    /////////////////// Task 1 //////////////////////////
    /////////////////////////////////////////////////////
    cout << "Задание 1" << endl;
    Power P1, P2(50.5, 11.1), P3 = P1;
    P1.print();
    P2.print();
    P3.print();
    P3.set(2.1, 12.345);
    P3.print();
    P1.calculate();
    P3.calculate();

    /////////////////////////////////////////////////////
    /////////////////// Task 2 //////////////////////////
    /////////////////////////////////////////////////////
    cout << endl << "Задание 2" << endl;
    RGBA color1, color2 = color1, color3(187, 40, 25, 55);
    color1.print();
    color2.print();
    color3.print();

    /////////////////////////////////////////////////////
   /////////////////// Task 3 //////////////////////////
   /////////////////////////////////////////////////////
    cout << endl << "Задание 3" << endl;
    Stack stack;
    stack.reset();
    stack.print();
    
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();
    return 0;
}