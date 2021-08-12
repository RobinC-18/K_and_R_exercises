#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIM 20

int main(int argc, char *argv[]) {
    int lim = 5;
    char c;
    char s[LIM];

    for (int i = 0; i < LIM - 1; i++) {
        if ((c = getchar()) == '\n')
            break;

        if (c == EOF)
            break;
        s[i] = c;
    }


}