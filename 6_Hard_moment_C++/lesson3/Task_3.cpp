#include <iostream>
#include <time.h>
#include <list>
#include <vector>
#include <array>
using namespace std;

////////////////////////////// Task 1 //////////////////////////////
void addAverage(list<double> &l)
{
    double sum = 0;
    for (auto iter : l)
    {
        sum += iter;
    }
    l.push_back(sum / l.size());
}

void printList(const list<double>& l)
{
    for (auto iter : l)
    {
        cout << iter << "  ";
    }
    cout << endl;
}
////////////////////////////////////////////////////////////////////

////////////////////////////// Task 2 //////////////////////////////
class Matrix
{
public:
    Matrix()
    {
        lines = 3;
        matrix.resize(lines);
        for (int i = 0; i < lines; ++i)
        {
            matrix[i].resize(lines);
            for (int j = 0; j < lines; ++j)
            {
                matrix[i][j] = rand() % 10 - 3;
            }
        };
    }


    int determinant()
    {
        return(matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1] - matrix[0][2] * matrix[1][1] * matrix[2][1] - matrix[0][0] * matrix[1][2] * matrix[2][1] - matrix[0][1] * matrix[1][0] * matrix[2][2]);
    }

    void printMatrix()
    {
        for (int i = 0; i < lines; i++)
        {
            for (int j = 0; j < lines; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

private:
    int lines;
    vector<vector<int>> matrix;
};
////////////////////////////////////////////////////////////////////

////////////////////////////// Task 3 //////////////////////////////
class Iterator
{
public:
    Iterator():object(nullptr){}
    Iterator(int *obj):object(obj){}

    int& operator++() { return *(++object); }
    int& operator--() { return *(--object); }
    int& operator++(int) { return *(object++); }
    int& operator--(int) { return *(object--); }
    int& operator+(int n) { return *(object + n); }
    int& operator-(int n) { return *(object - n); }
    int& operator*() { return *object; }
    bool operator!=(Iterator& it) { return object != it.object; }
    bool operator==(Iterator& it) { return object == it.object; }
    

private:
    int* object;
};




////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
int main()
{
    srand(time(0));
    ////////////////////////////////////////////////////////////////////
    list<double> l1 = { 2.5, 6.89, 7.8, 12.5, 56.09 };
    printList(l1);

    addAverage(l1);

    printList(l1);
    cout << endl;
    ////////////////////////////////////////////////////////////////////

    Matrix mx;
    mx.printMatrix();
    cout << "Determinant: " << mx.determinant() << endl;
    cout << endl;
    ////////////////////////////////////////////////////////////////////

    int arr[] = {0,1,2,3,4};
    Iterator _begin = begin(arr);
    Iterator  _end = end(arr);
    for (;_begin != _end; _begin++)
    {
        int x = *_begin;
        cout << arr[x] << "  ";
    }

    ////////////////////////////////////////////////////////////////////
    return 0;
}