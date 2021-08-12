#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIM 20

int htoi(char string[])
{
    int string_len;
    int total_len;
    total_len = strlen(string);

    if (string[0] == '0' && (string[1] == 'x' || string[1] == 'X'))
    {
        string_len = total_len - 2;
    }
    else
    {
        string_len = total_len;
    }

    int mult = 1;
    int total = 0;
    for (int i = total_len - 1; i >= total_len - string_len; i--)
    {
        if (isdigit(string[i]))
        {
            total += (string[i] - 48) * mult;
        }
        else if (string[i] >= 'a' && string[i] <= 'f')
        {
            total += (string[i] - 55) * mult;
        }
        else if (string[i] >= 'A' && string[i] <= 'F')
        {
            total += (string[i] - 87) * mult;
        }
        else
        {
            printf("Incorrect hex string: %c, tut tut \n", string[i]);
            return -1;
        }
        mult *= 16;
    }
    return total;
}

int main(int argc, char *argv[])
{
    char test_hex[] = "0x0150";

    int res = htoi(test_hex);

    printf("%d \n", res);
}