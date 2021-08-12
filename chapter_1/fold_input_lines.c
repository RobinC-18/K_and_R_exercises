#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 40

int main(int argc, char *argv[]) {

    int line_size, word_size;
    int nc;
    char c;

    char *line = calloc(LINE_LENGTH, sizeof(char));
    char *current_word = calloc(20, sizeof(char));

    line_size = word_size = nc = 0;
    while ((c = getchar()) != EOF) {
        nc++;
        if (c == '\n') {
            strcat(line, current_word);
            printf("%s \n", line);
            memset(current_word, 0, 20);
            memset(line, 0, LINE_LENGTH);
            nc = 0;
        }

        if (nc > 20 && c == ' ') {
            printf("%s \n", line);
            memset(line , 0, LINE_LENGTH);
            strcat(line, current_word);
            nc = strlen(current_word);
            memset(current_word, 0, 20);
        }
        
        if (nc < 20 && c == ' ') {
            strcat(current_word, &c);
            strcat(line, current_word);
            memset(current_word, 0, 20);
        } else if (nc < 20) {
            strcat(current_word, &c);
        }

    }
}