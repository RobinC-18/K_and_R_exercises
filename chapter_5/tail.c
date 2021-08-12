#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 100
#define MAXLEN 1000
char charstore[50000];

int mgetline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = '\0';
    s[i] = '\0';
    return i;
}

int usage(void)
{
    printf("Please use -n to specify the number of lines or leave blank for 10 lines\n");
    return -1;
}

int main(int argc, char *argv[])
{
    char *lines_to_print[MAXLINES];
    char *s;
    int nlines = 10;
    int len;
    char line[MAXLINES];

    s = *++argv;

    if (argc > 2 && strcmp(s, "-n") && s[0] == '-')
        return usage();

    ++argv;
    if (argc > 2 && !strcmp(s, "-n") && isdigit(*argv[0]))
    {
        int lines = atoi(*argv);
        if (lines < MAXLINES)
            nlines = lines;
        else
            nlines = MAXLINES;
    }
    else if (argc > 2 && !strcmp(s, "-n") && !isdigit(*argv[0]))
    {
        return usage();
    }

    int i = 0;
    char *p = charstore;
    while ((len = mgetline(line, MAXLEN)) > 0)
    {   

        // line[len - 1] = '\0';

        strcpy(p, line);
        lines_to_print[i] = p;
        i = (i + 1) % nlines;
        p += len;
    }

    for (int j = 0; j < nlines; j++)
    {
        printf("%s\n", lines_to_print[i]);
        i = (i + 1) % nlines;
    }
}