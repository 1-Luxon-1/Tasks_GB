#include <iostream>

class Stack
{
public:
	Stack()
	{
		arrPtr = new int[10];
		size = 0;
	}

	Stack(Stack& st)
	{
		arrPtr = new int[10];
		size = st.size;
		for (size_t i = 0; i < 10; i++)
		{
			arrPtr[i] = st.arrPtr[i];
		}
	}

	~Stack()
	{
		delete [] arrPtr;
	}

	void reset()
	{
		for (size_t i = 0; i < size; i++)
		{
			arrPtr[i] = 0;
		}
		size = 0;
	}

	bool push(int num)
	{
		if (size <= 10)
		{
			arrPtr[size] = num;
			size++;
			return true;
		}
		return false;
	}

	int pop()
	{
		if (size != 0)
		{
			int temp = arrPtr[size - 1];
			arrPtr[size - 1] = 0;
			size--;
			return temp;
		}
		else
			std::cout << "Stack is empty" << std::endl;
	}

	void print()
	{
		std::cout << "( ";
		for (size_t i = 0; i < size; i++)
		{
			std::cout << arrPtr[i] << " ";
		}
		std::cout << ")" << std::endl;
	}
private:
	int *arrPtr;
	size_t size;
};