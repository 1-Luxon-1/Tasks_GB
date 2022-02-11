#include<iostream>
#include<time.h>
using namespace std;

const size_t SIZE = 8;
const size_t SIZE5 = 5;
//--------------------------------------------------------------------
void arrDisplay(const double *arr, size_t sizeArr);
void arrDisplay(const int* arr, size_t sizeArr);					// ������� ��� ������ �������
void arrDisplay(const unsigned short* arr, size_t sizeArr);
//--------------------------------------------------------------------
void task2Change(unsigned short* arr, size_t sizeArr);
void task3Add(int* arr, size_t sizeArr);
void task4offset(int* arr, size_t sizeArr, int n);
bool task5CheckBalance(int* arr,size_t sizeArr);


int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(0));
	//-------------------------------------------------------------------
	// 1 �������
	//-------------------------------------------------------------------
	cout << "1 �������" << endl;
	double array1[] = {1.1, 5.5, 12.21, 32.23, 5.5, 3.3, 11.11, 4.4};
	arrDisplay(array1, SIZE);


	//-------------------------------------------------------------------
	// 2 �������
	//-------------------------------------------------------------------
	cout << "\n\n2 �������" << endl;
	unsigned short array2[SIZE];
	// ���������� �������
	for (int i = 0; i < SIZE; i++)
	{
		array2[i] = rand() % 2;
	}
	cout << "������ �� ���������:    ";
	arrDisplay( array2, SIZE);
	task2Change(array2, SIZE);
	cout << "������ ����� ���������: ";
	arrDisplay(array2, SIZE);


	//-------------------------------------------------------------------
	// 3 �������
	//-------------------------------------------------------------------
	cout << "\n\n3 �������" << endl;
	int array3[SIZE];
	task3Add(array3, SIZE);
	arrDisplay(array3, SIZE);


	//-------------------------------------------------------------------
	// 4 �������
	//-------------------------------------------------------------------
	cout << "\n\n4 �������" << endl;
	int array4[SIZE];
	int n;
	for (int i = 0; i < SIZE; i++)
	{
		array4[i] = rand() % 5;
	}
	cout << "������: ";
	arrDisplay(array4, SIZE);
	cout << "�� ������� ����������� ������ (\"+\" � ������ ������� \"-\" � �����): ";
	cin >> n;
	task4offset(array4, SIZE, n);
	cout << "������ ����� ��������: ";
	arrDisplay(array4, SIZE);


	//-------------------------------------------------------------------
	// 5 �������
	//-------------------------------------------------------------------
	cout << "\n\n5 �������" << endl;
	int array5[SIZE5] = { 1, 1, 1, 2, 1 };
	arrDisplay(array5, SIZE5);
	cout << boolalpha << task5CheckBalance(array5, SIZE5) << endl;;
return 0;
}


//---------------------------------------------------------------------
// ������� ��� ������ �������
//---------------------------------------------------------------------
void arrDisplay(const double *arr, size_t sizeArr)
{
	for (int i = 0; i < sizeArr; i++)
	{
		cout << *(arr + i) << "  ";
	}
	cout << endl;
}

void arrDisplay(const int* arr, size_t SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << *(arr + i) << "  ";
	}
	cout << endl;
}
void arrDisplay(const unsigned short* arr, size_t sizeArr)
{
	for (int i = 0; i < sizeArr; i++)
	{
		cout << *(arr + i) << "  ";
	}
	cout << endl;
}
//------------------------------------------------------------------

void task2Change(unsigned short* arr, size_t sizeArr)
{
	for (int i = 0; i < sizeArr; i++)
	{
		if (*(arr + i) == 0)
		{
			*(arr + i) = 1;
		}
		else
			*(arr + i) = 0;
	}
}
//--------------------------------------------------------------------

void task3Add(int* arr, size_t sizeArr)
{
	*arr = 1;
	for (int i = 1; i < SIZE; i++)
	{
		*(arr + i) = *(arr + i - 1) + 3;
	}
}
//--------------------------------------------------------------------

void task4offset(int* arr, size_t sizeArr, int n)
{
	int temp;
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = sizeArr-1; j > 0; j--)
			{
				temp = *(arr + j);
				*(arr + j) = *(arr + j - 1);
				*(arr + j - 1) = temp;
			}
		}
	}
	else
		if (n < 0)
		{
			for (int i = 0; i > n; i--)
			{
				for (int j = 0; j < sizeArr - 1; j++)
				{
					temp = *(arr + j);
					*(arr + j) = *(arr + j + 1);
					*(arr + j + 1) = temp;
				}
			}
		}
		else
		{
			cout << "��� ��������. �� ����� 0 !!!" << endl;
		}
}
//------------------------------------------------------------------
bool task5CheckBalance(int* arr, size_t sizeArr)
{
	bool result = false;;
	int stop = 1, sum1, sum2;
	do
	{
		sum1 = 0;
		sum2 = 0;
		for (int j = 0; j < sizeArr; j++)
		{
			if (j != stop)
			{
				sum1 += arr[j];
			}
			else
			{
				break;
			}
		}
		for (int j = sizeArr-1; j > 0; j--)
		{
			if (j != stop-1)
			{
				sum2 += arr[j];
			}
			else
			{
				break;
			}
		}
		if (sum1 == sum2)
		{
			result = true;
			break;
		}
		stop++;
	}while (stop < sizeArr);
	return result;
}
