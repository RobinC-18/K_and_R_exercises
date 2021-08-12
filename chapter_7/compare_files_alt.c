#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAXLINELEN 1000

int mygetline(char *line, int max, FILE *file)
{
    if (fgets(line, max, file) == NULL)
        return 0;
    else
        return strlen(line);
}

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    char current_line_f1[MAXLINELEN];
    char current_line_f2[MAXLINELEN];

    if (argc < 3 || argc > 4)
    {
        printf("Please specify 2 files to compare\n");
        return -1;
    }

    if ((fp1 = fopen(argv[1], "r")) == NULL)
    {
        printf("Cannot open %s\n", argv[1]);
        return -1;
    }
    if ((fp2 = fopen(argv[2], "r")) == NULL)
    {
        printf("Cannot open %s\n", argv[2]);
        return -1;
    }

    while (mygetline(current_line_f1, MAXLINELEN, fp1) != 0)
    {
        mygetline(current_line_f2, MAXLINELEN, fp2);
        if (strcmp(current_line_f1, current_line_f2) != 0)
        {
            printf("line 1: %s\n", current_line_f1);
            printf("line 2: %s\n", current_line_f2);
            return -1;
        }
    }
}