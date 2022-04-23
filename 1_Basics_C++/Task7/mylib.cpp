#include<iostream>
namespace Mylib
{

	void fillArr(float arr[], const size_t size)
	{
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = rand()%10-5;
		}
	}

	void printArr(const float arr[], const size_t size)
	{
		for (size_t i = 0; i < size; i++)
		{
			std::cout << arr[i] << ' ';
		}
		std::cout << std::endl;
	}

	void countPositiveNegative(const float arr[], const size_t size)
	{
		int pos = 0, neg = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] > 0)
			{
				pos++;
			}
			else
				if (arr[i] < 0)
				{
					neg++;
				}
		}
		std::cout << "Положительных элементов " << pos << ", отрицательных " << neg << std::endl;
	}
}