#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>

//-------------------------------------------------------------------------
void arrFill(const size_t n);
void arrShow(const int *arr, const size_t n);
int** arrDoubleCreate(const size_t m, const size_t n);
int** arrDoubleFill(int** arr, const size_t m, const size_t n);
void arrDoubleShow(int** arr, const size_t m, const size_t n);
void arrDoubleRelease(int** arr, const size_t m);

void writeOneFile(std::string str);
void writeTwoFile(std::string str);
void glueFile(std::string strNew, std::string str1, std::string str2);
void checkWord(std::string file, std::string word);
//-------------------------------------------------------------------------

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(0));
	//---------------------------------------------------------------------
	// 1 задание
	//---------------------------------------------------------------------
	size_t num;
	std::cout << "n = ";
	std::cin >> num;
	arrFill(num);
	std::cout << std::endl;

	//---------------------------------------------------------------------
	// 2 задание
	//---------------------------------------------------------------------
	const size_t m = 4;
	const size_t n = 4;
	int** ptrArr;
	std::cout << std::endl;
	ptrArr = arrDoubleCreate(m, n);
	arrDoubleFill(ptrArr, m, n);
	arrDoubleShow(ptrArr, m, n);
	arrDoubleRelease(ptrArr, m);

	//---------------------------------------------------------------------
	// 3 задание
	//---------------------------------------------------------------------
	std::string nameFile1, nameFile2;
	std::cout << "\nВведите название 1-го файла: ";
	std::cin >> nameFile1;
	writeOneFile(nameFile1);
	std::cout << "\nВведите название 2-го файла: ";
	std::cin >> nameFile2;
	writeTwoFile(nameFile2);
	
	//---------------------------------------------------------------------
	// 4 задание
	//---------------------------------------------------------------------
	std::string nameFile3;
	std::cout << "\nВведите название файла, куда производить копирование: ";
	std::cin >> nameFile3;
	glueFile(nameFile3, nameFile1, nameFile2);

	//---------------------------------------------------------------------
	// 5 задание
	//---------------------------------------------------------------------
	std::string word, fileSearchWord;
	std::cout << "Введите слово, наличие которого нужно проверить в файле (на латинице): ";
	std::cin >> word;
	std::cout << "Введите название файла, в котором проверяем надичие слова: ";
	std::cin >> fileSearchWord;
	checkWord(fileSearchWord, word);
	return 0;
}


//-------------------------------------------------------------------------
void arrShow(const int* arr, const size_t num)
{
	for(size_t i=0; i < num; i++)
	{
		std::cout << arr[i] << ' ';
	}
}

//-------------------------------------------------------------------------
void arrFill(const size_t num)
{
	int* arrDegTwo;
	arrDegTwo = new (std::nothrow) int[num];
	if (arrDegTwo != nullptr)
	{
		for (size_t i = 0; i < num; i++)
		{
			*(arrDegTwo + i) = pow(2,i);
		}
		arrShow(arrDegTwo, num);
		delete[] arrDegTwo;
		arrDegTwo = nullptr;
	}
	else
	{
		std::cout << "Ошибка! Невозможно выделить память." << std::endl;
	}
}

//-------------------------------------------------------------------------

int** arrDoubleCreate(const size_t m, const size_t n)
{
	int** ptrArr;
	ptrArr = new (std::nothrow) int* [m];
	if (ptrArr != nullptr)
	{
		for (size_t i = 0; i < n; i++)
		{
			ptrArr[i] = new(std::nothrow) int[n];
			if (ptrArr[i] == nullptr)
			{
				std::cout << "Ошибка! Нет свободной памяти.";
				exit(1);
			}
		}
	}
	else
	{
		std::cout << "Ошибка! Нет свободной памяти.";
	}
	return ptrArr;
}

//-------------------------------------------------------------------------
int** arrDoubleFill(int** arrPtr, const size_t m, const size_t n)
{
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			*(*(arrPtr + j) + i) = rand() % 10 + 1;
		}
	}
	return arrPtr;
}

//-------------------------------------------------------------------------
void arrDoubleShow(int** arrPtr, const size_t m, const size_t n)
{
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			std::cout << *(*(arrPtr + j) + i) << ' ';
		}
		std::cout << std::endl;
	}
}

//-------------------------------------------------------------------------
void arrDoubleRelease(int** arr, const size_t m)
{
	for (size_t i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;
}

//-------------------------------------------------------------------------
void writeOneFile(std::string str1)
{
	const size_t countStr = 50;
	std::ofstream fout(str1);
	for (size_t i = 0; i < countStr; i++)
	{
		fout << "2 to the degree of " << i << " = " << pow(2, i) << std::endl;
	}
	fout.close();
}

//-------------------------------------------------------------------------
void writeTwoFile(std::string str2)
{
	const size_t pastCount = 50;
	const size_t countStr = 100;
	std::ofstream fout(str2);
	for (size_t i = pastCount; i < countStr; i++)
	{
		fout << "2 to the degree of " << i << " = " << pow(2, i) << std::endl;
	}
	fout.close();
}

//-------------------------------------------------------------------------
void glueFile(std::string strNew, std::string str1, std::string str2)
{
	std::ofstream foutNew(strNew);
	std::ifstream fin1(str1);
	std::string s;
	if (fin1.is_open())
	{
		while (!fin1.eof())
		{
			getline(fin1,s);
			foutNew << s << std::endl;
		}
	}
	else
	{
		std::cout << "Ошибка! Не получилось открыть файл.";
	}
	fin1.close();
	std::ifstream fin2(str2);
	if (fin2.is_open())
	{
		while (!fin2.eof())
		{
			getline(fin2, s);
			foutNew << s << std::endl;
		}
	}
	else
	{
		std::cout << "Ошибка! Не получилось открыть файл.";
	}
	fin2.close();
	foutNew.close();
}

//-------------------------------------------------------------------------
void checkWord(std::string nameFile, std::string searchWord)
{
	std::ifstream fin(nameFile);
	std::string str;
	if (fin.is_open())
	{
		getline(fin, str);
		if (str.find(searchWord) != std::string::npos)
		{
			std::cout << "Строка присутствует в файле!" << std::endl;
		}
		else
		{
			std::cout << "Строка не найдена." << std::endl;
		}
	}
	else
	{
		std::cout << "Ошибка! Не получилось открыть файл.";
	}
}