#include <iostream>
#include <algorithm>
#include <time.h>
#include <vector>
#include <utility>
#include <chrono>
#include <string>
#include <fstream>
//#include <string_view>
using namespace std;

//////////////////////////// Task 1 ////////////////////////////
template <typename T>
void Swap(T** ptr1, T** ptr2)
{
    T* tempptr = move(*ptr1);
    *ptr1 = move(*ptr2);
    *ptr2 = move(tempptr);
}
////////////////////////////////////////////////////////////////

//////////////////////////// Task 2 ////////////////////////////
template <typename T>
void SortPointers(vector<T*>&v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j < v.size()-1; j++)
        {
            if (*v[j] > *v[j + 1])
            {
                T* temp = move(v[j]);
                v[j] = move(v[j + 1]);
                v[j + 1] = move(temp);
            }
        }
    }
}

template <typename T>
void printVecPtr(vector<T*> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << " " << *vec[i];
    }
}
////////////////////////////////////////////////////////////////


//////////////////////////// Task 3 ////////////////////////////
class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;
    
    std::string m_name;
    std::chrono::time_point<clock_t> m_beg;

    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
public:
    Timer() : m_beg(clock_t::now()) { }
    Timer(std::string name) : m_name(name), m_beg(clock_t::now()) { }

    void start(std::string name) 
    {
        m_name = name;
        m_beg = clock_t::now();
    }

    void print() const 
    {
        std::cout << m_name << ":\t" << elapsed() * 1000 << " ms" << '\n';
    }
};




int countingUseCount_ifAndFind(const string& str)
{
    Timer timer("count_if and find");

    const string vowels = "AEIOUYaeiouy";
    int count = std::count_if(str.begin(), str.end(), [&vowels](char c) {return (vowels.find(c) != string::npos); });

    timer.print();
    return count;
}


int countingUseCount_ifAndFor(const string& str)
{
    Timer timer("count_if and for");

    const string vowels = "AEIOUYaeiouy";
    int count = std::count_if(str.begin(), str.end(), [&vowels](char c) 
        {
            for (int i = 0; i < 12; i++)
            {
                if (c == vowels[i])
                    return true;
            }
            return false;
        });

    timer.print();
    return count;
}


int countingUseForAndFind(const string& str)
{
    Timer timer("for and find");

    int count = 0;
    string vowels = "AEIOUYaeiouy";
    for (int i = 0; i < str.length();i++)
    {
        if (vowels.find(str[i]) != string::npos)
        {
            count++;
        }
    }

    timer.print();
    return count;
}


int countingUse2For(const string& str)
{
    Timer timer("for and for");

    int count = 0;
    string vowels = "AEIOUYaeiouy";
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (str[i] == vowels[j])
                count++;
        }
    }

    timer.print();
    return count;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

int main()
{
    srand(time(0));
    int a = 5, b = 10;
    int* aPtr = &a;
    int* bPtr = &b;
    Swap<int>(&aPtr, &bPtr);
    cout << "&a = " << &a << "  &b = " << &b << endl;
    cout << "aPtr = " << aPtr << "  bPtr = " << bPtr << endl;
    cout << "*aPtr = " << *aPtr << "  *bPtr = " << *bPtr << endl << endl;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    vector<double*> vec;

    double arr[10];
    for (size_t i = 0; i < 10; i++)
    {
        arr[i] = ((double)(rand() % 100 / (double)(rand() % 10 + 1)));
    }

    for (size_t i = 0; i < 10; i++)
    {
        vec.push_back(&arr[i]);
    }

    cout << "vec: ";
    printVecPtr<double>(vec);
    cout << endl;

    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << "  ";
    }

    SortPointers(vec);
    cout << endl << "vec: ";
    printVecPtr<double>(vec);
    cout << endl;

    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << "  ";
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ifstream fin("War_and_Peace.txt");
    string str;
    string s1;
    if (!fin)
        cerr << "Error. File didn't open!" << endl;
    else
    {
        while (!fin.eof())
        {
            getline(fin, str);
            s1 += str;
        }
    }
    cout << endl << endl;
    cout << "number of vowels: " << countingUseCount_ifAndFind(s1) << endl << endl;

    cout << "number of vowels: " << countingUseCount_ifAndFor(s1) << endl << endl;

    cout << "number of vowels: " << countingUseForAndFind(s1) << endl << endl;

    cout << "number of vowels: " << countingUse2For(s1) << endl << endl;

    fin.close();
    return 0;
}


