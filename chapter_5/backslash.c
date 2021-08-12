#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    u_int8_t *res = (u_int8_t *)malloc(10);  
    memcpy(res, "\264\010", 6);
    printf("%d\n", res[0]);
}