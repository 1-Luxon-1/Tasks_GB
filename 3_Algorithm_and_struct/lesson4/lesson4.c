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
/////////// I could not solve task4 using recursion ////////////////
//=====================================================
void genArray(char array[][8], int h)
{
    int barrier;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<8;j++)
        {
            barrier=rand()%8+1;
            if(i==0 && j==0)
            {
                array[i][j]='K';
            }
            else
                if(i==8-1 && j==h-1)
                {
                    array[i][j]='F';
                }
                else
                    if(barrier%3==0)
                    {
                        array[i][j]='#';
                    }
                    else
                        array[i][j]='-';
        }
    }
}

void showArray(char array[][8], int h)
{
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<8;j++)
        {
            printf("%c    ",array[i][j]);
        }
        printf("\n\n");
    }
}

int countStep(char array[][8], int h)
{
    int summStep=0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(array[i][j]!='#'&&(i==0 && j==0) || (i==h-1 && j==8-1) || (i==h-1 && j==0) || i==0 && j==8)
            {
                summStep+=3;
            }
            else
                if(array[i][j]=='-' && (i==0 || j==0 || i==h-1 || j==8-1))
                {
                    summStep+=5;
                }
                else
                    if(array[i][j]=='-')
                {
                    summStep+=6;
                }
                else
            if(array[i][j]=='#' && (i==0 && j==0) || (i==h-1 && j==8-1) || (i==h-1 && j==0) || i==0 && j==8)
            {
                summStep-=3;
            }
            else
                if(array[i][j]=='#' && (i==0 || j==0 || i==h-1 || j==8-1))
                {
                    summStep-=5;
                }
                    if(array[i][j]=='#')
                {
                    summStep-=6;
                }
        }
    }
    return summStep;
}
//=====================================================
//=====================================================

int main()
{
    srand(time(0));
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
    printf("%d to the degree of %d = %d\n", num, deg, degree(num, deg));
    ////////////////////////////////////////////

    ////////////////// Task 3 //////////////////
    int num2, deg2;
    printf("\n\nEnter to number: ");
    scanf("%d", &num2);
    printf("Enter to degree: ");
    scanf("%d", &deg2);
    printf("%d to the degree of %d = %d\n", num2, deg2, degEven(num2, deg2));
    ////////////////////////////////////////////

    ////////////////// Task 4 //////////////////
    const int i=8, j=8;
    char field[i][j];
    genArray(field,j);
    showArray(field,j);
    printf("\nNumber of moves from K to F = %d\n",countStep(field,j));
    ////////////////////////////////////////////

    return 0;
}
