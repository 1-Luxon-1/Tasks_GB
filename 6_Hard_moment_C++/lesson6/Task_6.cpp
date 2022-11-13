#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

/////////////////////// Task 1 ///////////////////////
mutex m;
void funcA()
{
	cout << __FUNCTION__ << endl;
}

void funcB()
{
	cout << __FUNCTION__ << endl;
}
//////////////////////////////////////////////////////

class pcount
{
public:
	friend	ostream& operator<<(ostream&, pcount&);
	pcount(thread& th)
	{
		t = &th;
	}
	void select(thread& th)
	{
		t = &th;
	}
private:
	thread* t;
};
ostream& operator<<(ostream& out, pcount& p)
{
	lock_guard mut(m);
	out << __FUNCTION__ << endl;
	out << p.t->get_id() << endl
		<< p.t->hardware_concurrency << endl;
	return out;
}
//////////////////////////////////////////////////////


/////////////////////// Task 2 ///////////////////////
int searchSimpleNumber(int i)
{
	int count = 1;
	int res = 2;
	for (int it = 3; count < i; it += 2)
	{
		for (int j = 2; j < it; j++)
		{
			if (it % j == 0)
				break;
			else if (j + 1 == it)
			{
				count++;
				res = it;
				cout << "Progress: " << ((double)count / i) * 100 << " %" << endl;
			}
		}
	}
	return res;
}
//////////////////////////////////////////////////////


/////////////////////// Task 3 ///////////////////////
void printVec(vector<int>& v)
{
	for (auto it : v)
	{
		cout << it << "  ";
	}
	cout << endl;
}

void addThing(vector<int> &v)
{
	while (v.size() != 0)
	{
		int i = 0;
		this_thread::sleep_for(1000ms);
		if (v.size() == 0)
			return;
		v.push_back(rand() % 1000);
		i++;
		cout << "Принёс: ";
		printVec(v);
	}
}

void theft(vector<int> &v)
{
	while (v.size() != 0)
	{

		int i = 0;
		this_thread::sleep_for(500ms);
		int max = v[0];
		for (auto it : v)
		{
			if (it > max)
			{
				max = it;
			}
			i++;
		}
		sort(v.begin(), v.end());
		v.pop_back();
		cout << "Украл: ";
		printVec(v);
	}
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");
	/////////////////////// Task 1 ///////////////////////
	thread th1(funcA);
	thread th2(funcB);
	pcount pc(th1);
	cout << pc << endl;
	pc.select(th2);
	cout << pc << endl;
	th1.join();
	th2.join();
	/////////////////////// Task 2 ///////////////////////

	int simpleNumber;
	int i;
	cout << "Введите номер простого числа: ";
	cin >> i;
	thread t2([&]() {simpleNumber = searchSimpleNumber(i); });

	cout << i << "-е простое число = " << simpleNumber << endl;


	/////////////////////// Task 3 ///////////////////////
	vector<int>things{ 2, 45, 213, 87, 875, 127, 753, 1111 };
	thread owner(addThing, ref(things));
	thread theif(theft, ref(things));
	//////////////////////////////////////////////////////

	t2.join();
	owner.join();
	theif.join();
return 0;
}
