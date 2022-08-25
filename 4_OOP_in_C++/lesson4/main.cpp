#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include "Task_4_1.cpp"
using namespace std;
ostream& operator<<(ostream& out, const Array& Arr)
{
	for (size_t i = 0; i < Arr.size; i++)
	{
		out << Arr.arrData[i] << " ";
	}
	return out;
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(0));
///////////////////////////////////////////////////////////
/////////////////////// Task 1 ////////////////////////////
///////////////////////////////////////////////////////////
	cout << " Задание 1 " << endl;
	Array Arr(10, 5);
	cout << Arr << endl;
	Arr[2] = 8;
	cout << Arr << endl;
	Arr.resize(9);
	Arr[8] = 1;
	cout << Arr << endl;
	Arr.push_back(2);
	cout << Arr << endl;
	Arr.pop_back();
	cout << Arr << endl;
	Arr.pop_front();
	cout << Arr << endl;
	Arr[3] = 4;
	Arr[2] = 9;
	Arr[6] = 2;
	cout << Arr << endl;
	Arr.sort();
	cout << "Sort:" << endl << Arr << endl;

///////////////////////////////////////////////////////////
/////////////////////// Task 2 ////////////////////////////
///////////////////////////////////////////////////////////
	cout << endl << " Задание 2 " << endl;
	
	//Array Arr2(15, 1);
	//for (size_t i = 0; i < 15; i++)
	//{
	//	Arr2[i] = rand() % 15;
	//}
	//
	//Arr2.sort();
	//int num = 0;
	//for (size_t i = 1; i < 15; i++)
	//{
	//	if (Arr2[i] > Arr2[i - 1])
	//	{
	//		num++;
	//	}
	//}
	//cout << Arr2 << endl;
	//cout << "Различных чисел: " << num << endl;
	

	vector<int> arr(10, 1);
	for (size_t i = 0; i < arr.size(); i++)
	{
		arr[i] = rand() % 15;
	}
	sort(arr.begin(), arr.end());
	int num = 0;
	for (size_t i = 1; i < arr.size(); i++)
	{
		if (arr[i] > arr[i - 1])
		{
			num++;
		}
	}
	
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Различных чисел: " << num << endl;

	return 0;
}