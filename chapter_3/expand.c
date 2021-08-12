#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void expand(char s1[], char s2[]) {

    int i, copy;
    copy = 0;
    for(i = 0; s1[i] == '-'; i++)
        ;
    
    int j = i;
    for(i = j; i < strlen(s1) - 2; i++) {
        if (s1[i+1] == '-') {
            char first = s1[i];
            for(int k = s1[i]; k <= s1[i+2]; k++) {
                s2[copy++] = k;
            }
            i += 2;
        } else {
            s2[copy++] = s1[i];
        }
    }

    for(int j = 0;  j < strlen(s2); j++) {
        printf("%c", s2[j]);
    }
    printf("\n");

}

int main(int argc, char *argv[]) {

    char input[] = "-a-z";
    char res[50];

    expand(input, res); 

}
