#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void strcatmine(char *s, char *t) {
    for ( ; *s != '\0'; s++) {
    }   
    // s--;

    for ( ; *t != '\0'; t++, s++) {
        *s = *t;
    }
    *s = '\0';
}

void strncatmine(char *s, char *t, size_t n) {
    for ( ; *s != '\0'; s++) {
    }

    for (int i = 0; *t != '\0' && i < n; t++, s++, i++) {
        *s = *t;
    }
    *s = '\0';
}

int strendmine(char *s, char *t) {
    for ( ; *s != '\0'; s++) {
    }
    int i = 0;
    for ( ; *t != '\0'; t++) {
        i++;
    }
    
    while (i > 0) {
        if (*s-- != *t--) {
            return 0;
        }
        i--;
    }
    return 1; 
}

int strncmpmine(char *s, char *t, size_t n) {
    for (int i = 0; *s != '\0' && i < n; i++, s++, t++) {
        if (*s != *t) {
            return *s - *t;
        }
    }
    return 0;
}

void strncpymine(char *s, char *t, size_t n) {
    int i;
    for (i = 0; *s != '\0' && i < n; i++, s++, t++) {
        *t = *s;
        // printf("%d in loop\n", i);
    }
    // printf("%d out of loop\n", i);
    *t = '\0';
}



int main(int argc, char *argv[]) {
    char s[30] = "I am really testing";
    char t[] = " testin";
    int x;
    clock_t start = clock();
    for (int i = 0; i < 100000000; i++) {
         x = strendmine(s, t);
    }
    clock_t end = clock();

    printf("strend res: %d \n", x);
    printf("%f\n", (double)(end - start) / CLOCKS_PER_SEC);

}