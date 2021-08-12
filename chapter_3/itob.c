#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int itob(int n, char s[], int b) {
    char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    int i = 0;
    int rem;

    if ( b < 2 || b > 36 ) {
        return -1;
    }
    
    do {
        s[i++] = digits[n % 15];
    } while ((n /= b) > 0);
    reverse(s);

    return 1;
}

int main(int argc, char *argv[]) {

    int n = 65;
    int b = 16;
    char s[32];

    itob(n, s, b);

    for (int j = 0; j < strlen(s); j++) {
        printf("%c", s[j]);
    }
    printf("\n");
}