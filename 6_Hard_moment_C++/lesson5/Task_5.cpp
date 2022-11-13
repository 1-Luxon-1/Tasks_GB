#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <deque>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;

///////////////////////////// Task 1 /////////////////////////////
template<typename T>
void countigWords(T beg, T en)
{
	unordered_map<string, int>m;
	for (auto it = beg; it < en; it++)
	{
		++m[*it];
	}

	vector<pair<string, int>>words(m.begin(), m.end());
	for (auto i : words)
	{
		if (i.second == 1)
		{
			cout << i.first << " ";
		}
	}
}
//////////////////////////////////////////////////////////////////

int main()
{
	setlocale(LC_ALL, "RUS");
	///////////////////////////// Task 1 ////////////////////////////
	array<string, 10>arrWords{ "array", "running", "keys", "keys", "values", "specific", "operator", "running", "array", "operator" };
	vector<string>vecWords{ "sleep", "running", "sleep", "running" };
	deque<string>decWords{ "coding", "checks", "read", "programm", "coding", "checks" };
	countigWords<array<string, 10>::iterator>(arrWords.begin(), arrWords.end());
	cout << endl;
	countigWords<vector<string>::iterator>(vecWords.begin(), vecWords.end());
	cout << endl;
	countigWords<deque<string>::iterator>(decWords.begin(), decWords.end());
	//////////////////////////////////////////////////////////////////

	///////////////////////////// Task 2 ////////////////////////////
	string str;
	cout << endl << "Введите текст: " << endl;
	getline(cin, str);
	cout << endl << "Вы ввели:" << endl;
	cout << str;
	multimap<int, string>mp;
	int num = 0;
	string tempstr;
	int begin = 0;
	int end = 0;
	for (auto it : str)
	{
		end++;
		if (it == '.' || it == '?' || it == '!' || it+1 == string::npos)
		{
			tempstr.clear();
			copy(str.begin() + begin, str.begin() + end, back_inserter(tempstr));
			num = count_if(str.begin() + begin, str.begin() + end, [](char c) { return (c == ' '); });
			mp.insert({ ++num,tempstr });
			begin = end + 1;
		}
	}
	cout << endl << endl;
	for (auto it : mp)
	{
		cout << "Количество слов: " << it.first << ":  " << it.second << endl;
	}

return 0;
}
