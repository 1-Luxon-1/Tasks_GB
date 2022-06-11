#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////////////////////////////////
/////////////////////// Task 1 //////////////////////////////////
/////////////////////////////////////////////////////////////////
void cezarEncryption(char *str, int key)
{
    int i = 0;
    while(str[i] != '\0')
    {
        str[i] = (int)str[i] + key;
        i++;
    }
}

void cezarDecryption(char *str, int key)
{
    int i = 0;
    while(str[i] != '\0')
    {
        str[i] -= key;
        i++;
    }
}

printArr(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        printf("%c ", str[i]);
        i++;
    }
}


int main()
{

/////////////////////////// Task 1 /////////////////////////////
////////////////////////////////////////////////////////////////
    int key = 3;
    char strCezar[] = {'A', 'B', 'C', 'D', 'E', '\0'};
    printArr(strCezar);
    printf("\n");
    cezarEncryption(strCezar, key);
    printArr(strCezar);
    printf("\n");
    cezarDecryption(strCezar, key);
    printArr(strCezar);

    return 0;
}
