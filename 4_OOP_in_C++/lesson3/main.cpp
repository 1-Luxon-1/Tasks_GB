#include <iostream>
#include "Task_3_1.cpp"
#include "Task_3_2.cpp"
#include "Task_3_3.cpp"

using namespace std;

/////// Перегруженный оператор << для 3 задания ///////

ostream& operator<<(ostream& output, const Fraction& f)
{
	output << f.num << "/" << f.den;
	return output;
}
//////////////////////////////////////////////////////

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
//////////////////////////////////////////////////////////////////
//////////////////// Task 1 //////////////////////////////////////
//////////////////////////////////////////////////////////////////
    cout << " Задание 1 " << endl;
    Parallelogram parallelogram;
    Circle circle;
    Rectangle rectangle;
    Square square;
    Rhombus rhombus;

    Figure* areaFigure = &parallelogram;
    cout << "Площадь параллелограмма: " << areaFigure->area() << endl;
    
    areaFigure = &circle;
    cout << "Площадь круга: " << areaFigure->area() << endl;

    areaFigure = &rectangle;
    cout << "Площадь прямоугольника: " << areaFigure->area() << endl;

    areaFigure = &square;
    cout << "Площадь квадрата: " << areaFigure->area() << endl;

    areaFigure = &rhombus;
    cout << "Площадь ромба: " << areaFigure->area() << endl;


//////////////////////////////////////////////////////////////////
//////////////////// Task 2 //////////////////////////////////////
//////////////////////////////////////////////////////////////////
    cout << endl <<" Задание 2 " << endl;
    Car car("BMW", "3");
    PassengerCar car2("Audi", "A5", 150.0);
    Bus car3("Liaz", "1", 32);
    Minivan car4("VW", "Multivan", 160.0, 7);


//////////////////////////////////////////////////////////////////
//////////////////// Task 3 //////////////////////////////////////
//////////////////////////////////////////////////////////////////
    cout << endl << " Задание 3 " << endl;
    Fraction f1(13, 31), f2(7, 9), f3 = f1;
    cout << "f1 + f2 = " << f1 + f2 << endl;
    cout << "f1 - f3 = " << f1 - f3 << endl;
    cout << "f2 * f3 = " << f2 * f3 << endl;
    cout << "f1 / f3 = " << f1 / f3 << endl;
    if (f1 == f2)
        cout << "f1 == f2: true" << endl;
    else
        cout << "f1 == f2: false" << endl;

    if (f1 != f2)
        cout << "f1 != f2: true" << endl;
    else
        cout << "f1 != f2: false" << endl;

    if (f1 > f2)
        cout << "f1 > f2: true" << endl;
    else
        cout << "f1 > f2: false" << endl;

    if (f1 < f2)
        cout << "f1 < f2: true" << endl;
    else
        cout << "f1 < f2: false" << endl;

    if (f1 >= f2)
        cout << "f1 >= f2: true" << endl;
    else
        cout << "f1 >= f2: false" << endl;

    if (f1 <= f2)
        cout << "f1 <= f2: true" << endl;
    else
        cout << "f1 <= f2: false" << endl;
    
return 0;
}
