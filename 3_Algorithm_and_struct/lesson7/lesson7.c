#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include <time.h>

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
int* initArray(int* array,const int n)
{
    array = (int*) calloc(sizeof(int), n);
    return array;
}

void fillArray(int *arr, const int n)
{
    for(int i=0;i<n;++i)
    {
        *(arr+i)=rand()%10;
    }
}

void printArray(int *arr,int n)
{
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%3d", arr[i]);
    }
}

void swap(int *a, int* b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}


void sortInserts(int* arr, int len)
{
    int temp, pos;
    for (int i = 1; i < len; ++i)
    {
        temp = arr[i];
        pos = i - 1;
        while (pos >= 0 && arr[pos] > temp)
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}


void sortHoar(int* arr, int first, int last)
{
    int i = first;
    int j = last;

    int x = arr[(first + last) / 2];

    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last) sortHoar(arr, i, last);
    if (first < j) sortHoar(arr, first, j);
}

int searchMedian(int *arr, const int n)
{
    if((arr[0]>=arr[n/2] && arr[0]<=arr[n-1]) || (arr[0]<=arr[n/2] && arr[0]>=arr[n-1]))
        return 0;

    if((arr[n/2]>=arr[0] && arr[n/2]<=arr[n-1]) || (arr[n/2]<=arr[0] && arr[n/2]>=arr[n-1]))
        return n/2;

    if((arr[n-1]>=arr[n/2] && arr[n-1]<=arr[0]) || (arr[n-1]<=arr[n/2] && arr[n-1]>=arr[0]))
        return n-1;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

/////////////////////// Task 1 ///////////////////////
void modFastSort(int* arr, const int n)
{
    if(n<=10)
    {
        sortInserts(arr, n);
    }
    else
    {
        int median=searchMedian(arr, n);
        swap(&arr[median], &arr[n/2]);
        sortHoar(arr,0,n-1);
    }
}
//////////////////////////////////////////////////////


int main()
{
    setlocale(LC_ALL,"RUSSIAN");
    srand(time(0));

    ///// Task 1 /////
    const int n = 13;
    int** array=initArray(array, n);
    fillArray(array, n);
    printArray(array, n);
    modFastSort(array, n);
    printf("\nAfter modified fast sort:");
    printArray(array, n);
    //////////////////

return 0;
}
