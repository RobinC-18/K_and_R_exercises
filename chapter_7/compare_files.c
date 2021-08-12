#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define MAXLINELEN 1000

char *filecmp(FILE *, FILE *, char *, char *);

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    char current_line_f1[MAXLINELEN];
    char current_line_f2[MAXLINELEN];

    if (argc == 1)
    {
        /* no args; copy standard input */
        printf("Please provide two files");
        return 1;
    }
    else
        while (--argc > 0)
        {
            if ((fp1 = fopen(argv[1], "r")) == NULL)
            {
                printf("cat: can't open %s\n", *argv);
                return 1;
            }

            if ((fp2 = fopen(argv[2], "r")) == NULL)
            {
                printf("cat: can't open %s\n", *argv);
                return 1;
            }
            filecmp(fp1, fp2, current_line_f1, current_line_f2);
            fclose(fp1);
            fclose(fp2);
        }
    printf("line 1: %s\n", current_line_f1);
    printf("line 2: %s\n", current_line_f2);

    return 0;
}

char *filecmp(FILE *fp1, FILE *fp2, char *current_line_f1, char *current_line_f2)
{
    int f1, f2;
    int flag = 0;
    int pausef2 = 0;
    int pausef1 = 0;
    int i = 0;
    int j = 0;
    while (1)
    {
        if ((f1 = getc(fp1)) == EOF)
            break;

        if ((f2 = getc(fp2)) == EOF)
            break;

        if (f1 != f2)
            flag = 1;

        if (flag && f1 == '\n')
            pausef1 = 1;

        if (flag && f2 == '\n')
            pausef2 = 1;

        if (pausef1 && pausef2)
            break;

        if (f1 == '\n' && !pausef1)
        {
            i = 0;
            current_line_f1[i] = '\0';
            current_line_f1[i + 1] = '\0';
        }
        else if (f1 != '\n' && !pausef1)
        {
            current_line_f1[i++] = f1;
            current_line_f1[i] = '\0';
        }

        if (f2 == '\n' && !pausef2)
        {
                j = 0;
                current_line_f2[j] = '\0';
                current_line_f2[j + 1] = '\0';
        }
        else if (f2 != '\n' && !pausef2)
        {
                current_line_f2[j++] = f2;
                current_line_f2[j] = '\0';
        }
    }
    return current_line_f1;
}