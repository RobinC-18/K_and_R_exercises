#include <stdio.h>

int test_function(int x) {
    x = 5;

    return x;
}

int test_function_ptr(int *x) {
    *x = 5;
    return *x;
}

int main (int argc, char *argv[]){
    int x = 10;

    int res = test_function(x);
    printf("x = %d, res = %d \n", x, res);

    int res_ptr = test_function_ptr(&x);
    printf("x = %d, res_ptr = %d \n", x, res_ptr);
}