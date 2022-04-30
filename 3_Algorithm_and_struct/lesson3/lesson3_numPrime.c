#include <stdio.h>
#include <stdlib.h>
int prime(int x)
{
    if(x==2)
    {
        return 1;
    }
    else
    {
        for(int i=3;i<(x/2);i+=2)
        {
            if(x%i==0)
            {
                return 0;
            }
        }
        return 1;
    }
}

int main()
{
    int x;
    printf("Enter a number: ");
    scanf("%d",&x);

    if(prime(x)==1)
    {
        printf("Number is prime\n");
    }
    else
        printf("Number is not prime\n");
    return 0;
}
