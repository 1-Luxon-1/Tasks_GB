#include <iostream>
#include <assert.h>
//#include "Task_4_1.h"
using namespace std;

//ostream& operator<<(ostream& out, const Array& A);
/*
ostream& operator<<(ostream& out, const Array& Arr)
{
	for (size_t i = 0; i < Arr.size; i++)
	{
		out << Arr.arrData[i] << " ";
	}
	return out;
}

Array::Array() :size(0), arrData(nullptr){}

Array::Array(int length, int initVal)
{
	if (length > 0)
	{
		size = length;
		arrData = new int[size];
	}
	else
	{
		size = 0;
		arrData = nullptr;
	}
	
	for (size_t i = 0; i < size; i++)
	{
		arrData[i] = initVal;
	}
}

Array::~Array()
{
	delete[] arrData;
}

void Array::clear()
{
	delete[] arrData;
	size = 0;
	arrData = nullptr;
}

int& Array::operator [](int index)
{
	assert(index >= 0 && index < size);
	return arrData[index];
}

void Array::resize(int newSize)
{
	if (newSize <= 0)
	{
		clear();
		return;
	}
		
	int* data = new int[newSize];

	int elementToCopy = (newSize > size) ? size : newSize;
	for (size_t i = 0; i < elementToCopy; i++)
	{
		data[i] = arrData[i];
	}

	delete[]arrData;

	arrData = data;
	size = newSize;
}

void Array::insert(int value, int index)
{
	resize(size + 1);
	for (size_t i = size - 1; i > index; i--)
	{
		arrData[i] = arrData[i - 1];
	}
	arrData[index] = value;
}

void Array::push_back(int value)
{
	insert(value, size);
}

void Array::pop_back()
{
	resize(size - 1);
}

void Array::pop_front()
{
	for (size_t i = 0; i < size-1; i++)
	{
		arrData[i] = arrData[i + 1];
	}
	resize(size - 1);
}

void Array::sort()
{
	int i;
	int j;
	int step;
	int temp;

	for (step = (size) / 2; step > 0; step /= 2)
	{
		for (i = step; i < (size); ++i)
		{
			temp = arrData[i];
			for (j = i; j >= step; j -= step)
			{
				if (temp < arrData[j - step])
				{
					arrData[j] = arrData[j - step];
				}
				else
				{
					break;
				}
			}
			arrData[j] = temp;
		}
	}
}
*/


class Array
{
public:

	friend ostream& operator<<(ostream& out, const Array& A);

	Array() :size(0), arrData(nullptr){}

	Array(int length, int initVal)
	{
		if (length > 0)
		{
			size = length;
			arrData = new int[size];
		}
		else
		{
			size = 0;
			arrData = nullptr;
		}

		for (size_t i = 0; i < size; i++)
		{
			arrData[i] = initVal;
		}
	}

	~Array()
	{
		delete[] arrData;
	}

	void clear()
	{
		delete[] arrData;
		size = 0;
		arrData = nullptr;
	}

	int& operator [](int index)
	{
		assert(index >= 0 && index < size);
		return arrData[index];
	}

	void resize(int newSize)
	{
		if (newSize <= 0)
		{
			clear();
			return;
		}

		int* data = new int[newSize];

		int elementToCopy = (newSize > size) ? size : newSize;
		for (size_t i = 0; i < elementToCopy; i++)
		{
			data[i] = arrData[i];
		}

		delete[]arrData;

		arrData = data;
		size = newSize;
	}

	void insert(int value, int index)
	{
		resize(size + 1);
		for (size_t i = size - 1; i > index; i--)
		{
			arrData[i] = arrData[i - 1];
		}
		arrData[index] = value;
	}

	void push_back(int value)
	{
		insert(value, size);
	}

	void pop_back()
	{
		resize(size - 1);
	}

	void pop_front()
	{
		for (size_t i = 0; i < size-1; i++)
		{
			arrData[i] = arrData[i + 1];
		}
		resize(size - 1);
	}

	void sort()
	{
		int i;
		int j;
		int step;
		int temp;

		for (step = (size) / 2; step > 0; step /= 2)
		{
			for (i = step; i < (size); ++i)
			{
				temp = arrData[i];
				for (j = i; j >= step; j -= step)
				{
					if (temp < arrData[j - step])
					{
						arrData[j] = arrData[j - step];
					}
					else
					{
						break;
					}
				}
				arrData[j] = temp;
			}
		}
	}
private:
	int size;
	int* arrData;
};