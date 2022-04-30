#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

//=====================================================
int convToBinary(int x)
{
    int result;
    if(x>0)
    {
        return x%2+convToBinary(x/2)*10;
    }
    else
    {
        return (x%2);
    }
}

//=====================================================
int degree(int x, int y)
{
    if (y>=1)
    {
        return x*degree(x,--y);
    }
    else
    {
        return 1;
    }
}

//=====================================================
int degEven(int x, int y)
{


}

//=====================================================

int main()
{
    setlocale(LC_ALL,"RUSSIAN");

    ////////////////// Task 1 //////////////////
    int x;
    printf("Enter to number: ");
    scanf("%d", &x);
    printf("%d\n",convToBinary(x));
    ////////////////////////////////////////////

    ////////////////// Task 2 //////////////////
    int num, deg;
    printf("¬ведите число: ");
    scanf("%d", &num);
    printf("¬ведите степень: ");
    scanf("%d", &deg);
    printf("%d в степени %d = %d", num,deg,degree(num,deg));
    ////////////////////////////////////////////

    return 0;
}
