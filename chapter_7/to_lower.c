#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

/* lower: converts upper case to lower case */
/* upper: converts lower case to upper case */

int main(int argc, char *argv[])
{
    int c;
    printf("In lower\n");

    if (strcmp(argv[1], "lower") == 0)
        while ((c = getchar()) != EOF)
            putchar(tolower(c));
    else if (strcmp(argv[1], "upper") == 0)
        while ((c = getchar()) != EOF)
            putchar(toupper(c));
    else
        printf("Please use upper or lower to specify which one you want.\n");

    return 0;
}
