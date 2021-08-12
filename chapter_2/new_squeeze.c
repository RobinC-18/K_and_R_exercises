#include <stdio.h>
#include <string.h>

const char * squeeze(char s1[], char s2[]) {

    int i, j;
    int flag = 0;

    for (i = j = 0; i < strlen(s1); i++) {
        for (int k = 0; k < strlen(s2); k++) {
            if (s1[i] == s2[k]) {
                flag = 1;
            }
        }
        if (flag == 0) {
            s1[j++] = s1[i];
        }
        flag = 0;
    }
    s1[j] = '\0';
    return s1;
}

int main(int argc, char *argv[]) {

    char s1[] = "Hello, world";
    char s2[] = "lol";

    const char *res = squeeze(s1, s2);

    printf("%s\n", res);

}