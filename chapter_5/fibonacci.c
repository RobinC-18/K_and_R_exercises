#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int *func(void)
{
    int y[10] = {0,};
    int x = 0;
    int z[10] = {1,};

    printf("%p, %p\n", y, &y[9]);
    printf("%d\n", (char *)&y[9] - (char *)y);

    return &x;
}

int main(int argc, char *argv[]) {

    int x = 0;
    // printf("%p\n", &x);    
    // func();
    int *y = func();
    // printf("%p\n", y);

    // printf("%ld\n", &x - y);

}