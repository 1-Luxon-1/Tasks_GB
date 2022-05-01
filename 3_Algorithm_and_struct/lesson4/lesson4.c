#include <stdio.h>
#include <stdlib.h>

//=====================================================
int convToBinary(int x)
{
    int result;
    if (x > 0)
    {
        return x % 2 + convToBinary(x / 2) * 10;
    }
    else
    {
        return (x % 2);
    }
}

//=====================================================
int degree(int x, int y)
{
    if (y >= 1)
    {
        return x * degree(x, --y);
    }
    else
    {
        return 1;
    }
}

//=====================================================
int degEven(int x, int y)
{
    if (y > 0 && y % 2 == 0)
    {
        return degEven(x *= x, y /= 2);
    }
    else
    {
        if (y > 0 && y % 2 != 0)
        {
            return x * degEven(x, --y);
        }
        else
        {
            return 1;
        }
    }
}

//=====================================================
//=====================================================

int main()
{

    ////////////////// Task 1 //////////////////
    int x;
    printf("Enter to number: ");
    scanf("%d", &x);
    printf("%d\n", convToBinary(x));
    ////////////////////////////////////////////

    ////////////////// Task 2 //////////////////
    int num, deg;
    printf("Enter to number: ");
    scanf("%d", &num);
    printf("Enter to degree: ");
    scanf("%d", &deg);
    printf("%d to the degree of %d = %d", num, deg, degree(num, deg));
    ////////////////////////////////////////////

    ////////////////// Task 3 //////////////////
    int num2, deg2;
    printf("\n\nEnter to number: ");
    scanf("%d", &num2);
    printf("Enter to degree: ");
    scanf("%d", &deg2);
    printf("%d to the degree of %d = %d", num2, deg2, degEven(num2, deg2));
    ////////////////////////////////////////////


    return 0;
}