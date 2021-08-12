#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>


int main(int argc, char *argv[]) {

    printf("Range of int: %.0Lf \n", powl(2, sizeof(int) * 8));
    printf("Range of char: %.0Lf \n", powl(2, sizeof(char) * 8));


}