#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
int** initArray(int** array,const int row, const int column)
{
    array = (int**) calloc(sizeof(int*), row);
    for(int i=0;i<column;i++)
    {
        *(array+i)=(int*) calloc(sizeof(int), column);
    }
    return array;
}

void fillArray(int **arr, const int row, const int column)
{
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<column;++j)
        {
            *(*(arr+i)+j)=rand()%10;
        }
    }
}

void print1dArray(float *arr,int n)
{
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%6.1f", *(arr+i));
    }
}

void print2dArray(int **arr,const int row, const int column)
{
        for(int i=0;i<row;++i)
    {
        for(int j=0;j<column;++j)
        {
            printf("%3d",*(*(arr+i)+j));
        }
        printf("\n");
    }
}

void swap(int *a, int* b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

////////////////// Task 1 ////////////////////////////////
void bubbleSort(int **arr,int row, int column)
{
    int temp;
    for(int k=0;k<row*column;k++)
    {
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(j==column-1 && i<row-1 && (arr[i][j]>arr[i+1][0]))
            {
                swap(&arr[i][j],&arr[i+1][0]);
            }
            else
            if(j<column-1 && (*(*(arr+i)+j)>*(*(arr+i)+(j+1))))
            {
                swap(&arr[i][j],&arr[i][j+1]);
            }
        }
    }
    }
}
//////////////////////////////////////////////////////////////////////

void TrabParKnut(float *array, const int num)
{
    float temp;
    printf("Enter to 11 number\n");
    for(int i=0;i<num;i++)
    {
        printf("%d: ",i+1);
        scanf("%f", &array[i]);
    }
    print1dArray(array, num);
    for(int i=0;i<num/2/*<num*/;i++)
    {
        temp=array[i];
        array[i]=array[num-1-i];
        array[num-1-i]=temp;
    }
    print1dArray(array, num);
    printf("\n");
    for(int i=0;i<num;i++)
    {
        if(sqrt(fabs(array[i]))+5*pow(array[i],3)>400)
        {
            printf("%d: result > 400\n",i+1);
        }
        else
        {
            printf("%d: %.2f\n",i+1,sqrt(fabs(array[i]))+5*pow(array[i],3));
        }
    }
}

////////////////////////////////////////////////////////////////////////////
int main()
{
    srand(time(0));

    //Task 1//
    const int n = 5;
    const int m = 5;
    int** array=initArray(array, n, m);
    fillArray(array, n, m);
    print2dArray(array, n, m);

    printf("\nAfter bubble sorting:\n");
    bubbleSort(array, n, m);
    print2dArray(array, n, m);

    //Task 2//
    const int num = 11;
    float array2[num];

    TrabParKnut(array2, num);

    return 0;
}
/////////////////////////////////////////////////////////////////////////////
