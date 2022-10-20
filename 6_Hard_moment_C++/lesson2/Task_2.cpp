#include <iostream>
#include <time.h>
#include <vector>
#include <utility>
using namespace std;


template <typename T>
void Swap(T** ptr1, T** ptr2)
{
    T* tempptr = move(*ptr1);
    *ptr1 = move(*ptr2);
    *ptr2 = move(tempptr);
}

/*template <typename T>
void SortPointers(vector<T> **v)
{
    for (int iter : *v)
    {
        for (int iter : *v)
        {
            if (*v[iter] < *v[iter - 1])
            {
                T temp = *v[iter];
                *v[iter] = *v[iter + 1];
                *v[iter + 1] = temp;
            }
        }
    }
}*/

int main()
{
    int a = 5, b = 10;
    int* aPtr = &a;
    int* bPtr = &b;
    Swap(&aPtr, &bPtr);

    vector<double*> vec;
    
    return 0;
}
