#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
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
    for(int i = 0; i<n; ++i)
    {
        *(arr+i) = rand()%10;
    }
}

void printArray(int *arr,int n)
{
    printf("\n");
    for(int i  =0; i < n; i++)
    {
        printf("%3d", arr[i]);
    }
}

void swap(int *a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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
    if((arr[0] >= arr[n/2] && arr[0] <= arr[n-1]) || (arr[0] <= arr[n/2] && arr[0] >= arr[n-1]))
        return 0;

    if((arr[n/2] >= arr[0] && arr[n/2] <= arr[n-1]) || (arr[n/2] <= arr[0] && arr[n/2] >= arr[n-1]))
        return n/2;

    if((arr[n-1] >= arr[n/2] && arr[n-1] <= arr[0]) || (arr[n-1] <= arr[n/2] && arr[n-1] >= arr[0]))
        return n-1;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

/////////////////////// Task 1 ///////////////////////
void modFastSort(int* arr, const int n)
{
    if(n <= 10)
    {
        sortInserts(arr, n);
    }
    else
    {
        int median = searchMedian(arr, n);
        swap(&arr[median], &arr[n / 2]);
        sortHoar(arr,0,n - 1);
    }
}
//////////////////////////////////////////////////////


/////////////////////// Task 2 ///////////////////////
void bucketSortPositive(int* arr, int len)
{
    const int max = len;
    const int b = 10;
    int count = 0;
    int arrNotEven[max];

    int buckets[b][max+1];
    for (int i = 0; i < b; i++)
    {
        buckets[i][max] = 0;
    }

    for (int digit = 1; digit < 1000000000; digit*=10)
    {
        for (int i = 0; i < max; i++)
        {
            int d = (arr[i] / digit) % b;
            int counter = buckets[d][max];
            buckets[d][counter] = arr[i];
            counter++;
            buckets[d][max] = counter;
        }
        int idx = 0;
        for (int i = 0; i < b; i++)
        {
            count = 0;
            for (int j = 0; j < buckets[i][max]; j++)
            {
                if(buckets[i][j] == 0/*arrNotEven[count]*/)
                {
                    arr[idx++] = arrNotEven[count];
                    count++;
                }
                else
                {
                    arr[idx++] = buckets[i][j];
                }
            }
            buckets[i][max] = 0;
        }
    }
}
//////////////////////////////////////////////////////


int main()
{
    setlocale(LC_ALL,"RUSSIAN");
    srand(time(0));

    ///// Task 1 /////
    const int n = 13;
    int** array = initArray(array, n);
    fillArray(array, n);
    printArray(array, n);
    modFastSort(array, n);
    printf("\nAfter modified fast sort:");
    printArray(array, n);
    //////////////////

    ///// Task 2 /////
    const int n2 = 15;
    int** array2 = initArray(array2, n2);
    fillArray(array2, n2);
    printf("\n\n");
    printArray(array2, n2);
    bucketSortPositive(array2, n2);
    printf("\nAfter bucket sort:");
    printArray(array2, n2);
    //////////////////
return 0;
}
