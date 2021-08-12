#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]) {

    char array1[20] = "01234567890123456789";
    char array2[20] = "test";

    printf("%p \n", array1);
    printf("%p \n", array2);

    for(int i = 0; i < 80; i++) {
        printf("%c", array2[i]);
    }
}