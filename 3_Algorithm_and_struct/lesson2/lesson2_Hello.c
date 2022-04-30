#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"RUSSIAN");
    printf("Hello world!\nПривет мир!\n");
return 0;
}
