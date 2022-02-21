#include<iostream>
#include<fstream>
#include<time.h>
// 5(1) задание
#include "mylib.h"

// 2 задание
#define range(num1,num2) (num1>=0 && num1<num2)?true:false

// 3 задание
#define swapINT(a,b)\
{\
	int temp=a;\
	a = b;\
	b = temp;\
}
#define SIZE 5
void arrFill(int arr[], const size_t size);
void sort(int arr[], const size_t size);
void printArrINT(const int arr[], size_t size);

// 4 задание

#pragma pack (push,1)
struct Employee
{
	double id;
	double salary;
	unsigned short int age;
	char gender;
};
#pragma pack(pop)

void initStruct(Employee *e)
{
	std::cout << "\nвведите ID сотрудника: ";
	std::cin >> e->id;
	std::cout << "введите зарплату сотрудника: ";
	std::cin >> e->salary;
	std::cout << "введите возраст сотрудника: ";
	std::cin >> e->age;
	std::cout << "введите пол сотрудника: ";
	std::cin >> e->gender;
}

void printStruct(Employee* e)
{
	std::cout << "\nID сотрудника: " << e->id << std::endl;
	std::cout << "Заработная плата: " << e->salary << std::endl;
	std::cout << "Возраст: " << e->age << std::endl;
	std::cout << "Пол сотрудника: " << e->gender << std::endl;
}



int main()
{
	srand(time(0));
	setlocale(LC_ALL, "RUSSIAN");

	//----------------------------------------------------------
	// 5(1) задание
	//----------------------------------------------------------
	size_t size;
	std::cout << "Введите размер массива: ";
	std::cin >> size;
	float* array;
	array = new float[size];
	Mylib::fillArr(array, size);
	Mylib::printArr(array, size);
	Mylib::countPositiveNegative(array,size);

	//----------------------------------------------------------
	// 2 задание
	//----------------------------------------------------------
	size_t num1, num2;
	std::cout << "\nВведите число: ";
	std::cin >> num1;
	std::cout << "Введите конец диапазона: ";
	std::cin >> num2;
	std::cout<<std::boolalpha<<range(num1, num2);
	
	//----------------------------------------------------------
	// 3 задание
	//----------------------------------------------------------
	int array2[SIZE];
	arrFill(array2, SIZE);
	sort(array2, SIZE);
	printArrINT(array2, SIZE);

	//----------------------------------------------------------
	// 4 задание
	//----------------------------------------------------------
	Employee* e=new Employee;
	initStruct(e);
	printStruct(e);
	std::cout << "\nРазмер структуры: " << sizeof(*e) << std::endl;
	std::ofstream fout("file.txt");
	fout << "\nID сотрудника: " << e->id << std::endl;
	fout << "Заработная плата: " << e->salary << std::endl;
	fout << "Возраст: " << e->age << std::endl;
	fout << "Пол сотрудника: " << e->gender << std::endl;
	fout.close();

return 0;
}


//--------------------------------------------------------------
//--------------------------------------------------------------
void arrFill(int array[], const size_t size)
{
	std::cout << "\nЗаполните массив из 5 элементов: ";
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> array[i];
	}
}

//--------------------------------------------------------------
void sort(int array[], const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swapINT(array[j + 1], array[j]);
			}
		}
	}
}

//-------------------------------------------------------------
void printArrINT(const int arr[], const size_t SZ)
{
	for (size_t i = 0; i < SZ; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}