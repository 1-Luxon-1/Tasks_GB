#include<iostream>
#include<locale>
using namespace std;

//-------------------------------------------------------------
// 1 �������
//-------------------------------------------------------------
void Zadan1()
{
	const int MIN = 10;
	const int MAX = 20;
	int num1, num2;
	cout << "������� ��� �����\n������ �����: ";
	cin >> num1;
	cout << "������ �����: ";
	cin >> num2;
	if ((num1 + num2 >= MIN) && (num1 + num2 <= MAX))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
}

//-------------------------------------------------------------
// 2 �������
//-------------------------------------------------------------
void Zadan2()
{
	const int num1 = 4;
	const int num2 = 6;
	if (((num1 == num2) && (num1 == 10) && (num2 == 10)) || (num1 + num2 == 10))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
}
//-------------------------------------------------------------
// 3 �������
//-------------------------------------------------------------
void Zadan3()
{
	int i = 1;
	cout << "�������� ����� �� 1 �� 50: ";
	while (i != 50)
	{
		if (i % 2 != 0)
			cout << i << "  ";
		i++;
	}
	cout << endl;
}

//-------------------------------------------------------------
// 4 �������
//-------------------------------------------------------------
void Zadan4()
{
	int var, flag = 0;
	cout << "������� �����: ";
	cin >> var;
	for (int i = 2; i < var; i++)
	{
		if (var % i == 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		cout << "����� �� �������� �������" << endl;
	}
	else
	{
		cout << "����� �������" << endl;
	}
}

//-------------------------------------------------------------
// 5 �������
//-------------------------------------------------------------
void Zadan5()
{
	int year;
	do
	{
		cout << "������� ���: ";
		cin >> year;
		if (year <= 0)
		{
			cout << "�� ����� ������������� ����� !!! ������� �������������." << endl;
		}
	} while (year <= 0);

	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
	{
		cout << "\n��� ����������" << endl;
	}
	else
	{
		cout << "\n��� �� ����������" << endl;
	}
}
//-------------------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << "������� 1" << endl;
	Zadan1();
	cout << "\n������� 2" << endl;
	Zadan2();
	cout << "\n������� 3" << endl;
	Zadan3();
	cout << "\n������� 4" << endl;
	Zadan4();
	cout << "\n������� 5" << endl;
	Zadan5();
	return 0;
}