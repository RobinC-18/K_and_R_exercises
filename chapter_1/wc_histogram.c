#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN 1
#define OUT 0
#define ARRAY_LENGTH 12

int main(int argc, char *argv[]) {

    int nw, nc, state, word_length;
    int wspace_mult;
    char c;

    state = OUT;
    nw = nc = wspace_mult = word_length = 0;
    char input[200];
    fgets(input, 200, stdin);
    int word_lengths[ARRAY_LENGTH] = {0, };

    while ((c = input[nc]) != EOF && nc < strlen(input)) {
        nc++;
        if (c == ' ' || c == '\n' || c == '\t') {
            wspace_mult++;
            if (wspace_mult == 1) {
                word_lengths[word_length]++;
                word_length = 0;
                state = OUT;
            }
        }
        else if (state == OUT) {
            state = IN;
            nw++;
            word_length++;
        }
        else {
            word_length++;
            wspace_mult = 0;
        }
    }
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        int ratio = (word_lengths[i] * 60.0) / nw;
        // printf("%f \n", ratio);
        printf("%d: %.*s \n", i, ratio, "------------------------------------------------------------");
    }
}