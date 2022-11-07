#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <numeric>
#include<iomanip>
using namespace std;

/////////////////////// Task 1 ///////////////////////
template<typename T1, typename T2>
void insert_sorted(T1 &v, T2 num)
{
    auto pos(lower_bound(begin(v), end(v), num));
    v.insert(pos, num);
}
//////////////////////////////////////////////////////

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    vector<int> vec1;
    for (int i = 0; i < 10; i++)
    {
        vec1.push_back(rand() % 10);
    }

    sort(vec1.begin(), vec1.end());
    for_each(vec1.begin(), vec1.end(), [](int i) {cout << i << " "; });
    cout << endl;
    insert_sorted(vec1, 5);
    for_each(vec1.begin(), vec1.end(), [](int i) {cout << i << " "; });

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << endl << endl;
    vector<double>asign(100);
    vector<double>csign(100);
    generate(asign.begin(), asign.end(), []() {return (double)rand() / RAND_MAX * 5 + 3; });
    copy(asign.begin(), asign.end(), csign.begin());
    cout << endl << endl;
    transform(csign.begin(), csign.end(), csign.begin(), [](double i) {double partint; modf(i, &partint); return partint; });

    cout << "Аналоговый сигнал : " << endl;
    copy(asign.begin(), asign.end(), ostream_iterator<double>(cout, " "));
    cout << endl << endl << "Цифровой сигнал: " << endl;
    copy(csign.begin(), csign.end(), ostream_iterator<double>(cout, " "));

    cout << endl << "Ошибка: " << inner_product(asign.begin(), asign.end(), csign.begin(), 0, [](double x, double y) {return x + y; }, [](double x, double y) {return (x - y) * (x - y); }) << endl;

    return 0;
}