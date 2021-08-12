#include <stdio.h>
#include <stdlib.h>

static char daytab[2][13] = { {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month and day */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

int pday_of_year(int year, int month, int day)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    char *p = &daytab[leap][1];

    for (i = 1; i < month; i++)
        day += *p++;
    return day;
}

/* month_day: set month, day from day of year */

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

void pmonth_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    char *p = &daytab[leap][1];

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= *p++;
    *pmonth = i;
    *pday = yearday;
}

int main(int argc, char *argv[]) {
    int year = 2021;
    int month = 7;
    int day = 15;
    int yearday = 196;

    int res_month;
    int res_day;

    pmonth_day(2021, yearday, &res_month, &res_day);

    printf("%d\n", pday_of_year(year, month, day));
    printf("month: %d, day: %d\n", res_month, res_day);
}