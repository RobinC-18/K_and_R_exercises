#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000    /* max #lines to be sorted */
#define MAXMEMBUFF 50000 /* max #bytes of memory allowed */

char *lineptr[MAXLINES];
char charstore[MAXMEMBUFF];

int readlines(char *lineptr[], char *linestor, int nlines);
void writelines(char *lineptr[], int nlines, int reverse);

void myqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *s1, char *s2);

/* sort input lines */

int main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
    int numeric = 0;
    int reverse = 0;
    int c = 0;

    while (--argc > 0 && *++argv[0] == '-')
    {
        c = *argv[1];
        switch (c)
        {
        case 'n':
            numeric = 1;
            break;
        case 'r':
            reverse = 1;
            break;
        default:
            printf("Illegal option\n");
            break;
        }
    }
    if ((nlines = readlines(lineptr, charstore, MAXLINES)) >= 0)
    {
        myqsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines, reverse);
        return 0;
    }
    else
    {
        printf("error: input too big to sort \n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of any input line */
#define MAXSTOR 50000

int mgetline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], char *charstore, int maxlines)
{
    int len, nlines, total;
    char line[MAXLEN];
    char *p = charstore;
    char *linestop = charstore + MAXSTOR;

    total = 0;
    nlines = 0;

    while ((len = mgetline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || p + len > linestop)
            return -1;
        else
        {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
            total += len;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int reverse)
{
    int i;
    if (reverse)
    {
        for (int i = nlines - 1; i >= 0; i--)
            printf("%s\n", lineptr[i]);
    }
    else
    {
        for (i = 0; i < nlines; i++)
            printf("%s\n", lineptr[i]);
    }
}

/* qsort: sort v[left] ... v[right] into increasing order */
void myqsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);

    last = left;

    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    myqsort(v, left, last - 1, comp);
    myqsort(v, last + 1, right, comp);
}

/* swap: interchange v[i] and v[j] */

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
        return 0;
}

int mgetline(char *s, int lim)
{
    int c;
    char *t = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;

    *s = '\0';

    return s - t;
}

int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}