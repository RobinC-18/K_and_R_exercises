#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printd(int n)
{
    if (n < 0) 
    {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
    
}

void itoa(int n, char str[]) {
    static int i;
    if (n < 0)
    {
        i = 0;
        str[i++] = '-';
        n = -n;
    }
    if (n / 10)
        itoa(n / 10, str);
    else 
        i = 0;

    str[i++] = n % 10 + '0';
    str[i] = '\0';
    
}

int main(int argc, char *argv[]) {

    char str[20];

    printd(123);
    itoa(123, str);
    printf("\n%s \n", str);

}