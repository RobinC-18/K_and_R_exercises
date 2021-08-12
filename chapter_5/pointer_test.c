#include <stdio.h>
#include <stdlib.h>

void swap(int *px, int *py) 
{
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

int main(int argc, char *argv[])
{

    int x;
    int y;

    x = 10;
    y = 20;

    swap(&x, &y);
    printf("%d\n", x);
    printf("%d\n", y);

}
