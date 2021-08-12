#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN 1
#define OUT 0

int main(int argc, char *argv[]) {

    int nw, nc, state;
    int wspace_mult;
    char c;

    state = OUT;
    nw = nc = wspace_mult = 0;
    char input[200];
    char word[20];
    memset(word, 0, 20);

    printf("Please enter some words: ");

    // fgets(input, 200, stdin);
    while ((c = getchar()) != EOF) {
        nc++;
        if (c == ' ' || c == '\n' || c == '\t') {
            wspace_mult++;
            if (wspace_mult == 1) {
                printf("%s \n", word);
                memset(word, 0, 20);
                state = OUT;
            }
        }
        else if (state == OUT) {
            state = IN;
            nw++;
            strcat(word, &c);
        }
        else {
            strcat(word, &c);
            wspace_mult = 0;
        }
    }
}