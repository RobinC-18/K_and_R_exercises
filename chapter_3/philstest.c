#include <stdio.h>

int *i;

void fun()
{
    int b = 13;
    i = &b;
    printf("i: %p \n", i);
    printf("b: %p \n", &b);
}

void fun2() 
{ 
    int a = 15;
    printf("i: %p \n", i);
    printf("a: %p \n", &a);
}

int main()
{
    fun();
    printf("i: %d\n", *i);
    fun2();
    printf("i: %d\n", *i);
    return 0;
}