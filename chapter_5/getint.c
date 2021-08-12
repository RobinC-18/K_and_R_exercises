#include <ctype.h>
#include <stdio.h>

#define SIZE 5
#define BUFSIZE 100         /* buffer size */

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters!\n");
    else
        buf[bufp++] = c;
}

int getint(int *pn)
{
    int c, sign;

    while(isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();

    if (!isdigit(c))
        return -1;

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getfloat(float *pn)
{
    int c, sign;
    float power;

    while(isspace(c=getch()))
        ;

    if( !isdigit(c) && c!=EOF && c!= '+' && c != '-' && c != '.')
    {
        ungetch(c);
        return 0;
    }
    
    sign = ( c == '-') ? -1: 1;

    if( c == '+' || c == '-')
        c = getch();

    for(*pn = 0.0 ; isdigit(c);c=getch())
        *pn = 10.0 * *pn + (c - '0');
    if( c == '.')
        c = getch();

    for(power=1.0;isdigit(c);c=getch())
    {
        *pn = 10.0 * *pn + (c - '0');   /* fractional part */
        power *= 10.0;
    }

    *pn  *= sign / power;

    if( c != EOF)
        ungetch(c);
    
    return c;
}


int main(void)
{
    int n, s, int_array[SIZE], getint(int *);
    float float_array[SIZE];

    for(n = 0; n < SIZE && getfloat(&float_array[n]) != EOF; n++)
    {
        printf("storing in n = %d, getfloat %f\n", n, float_array[n]);
    }
    
    for(n=0; n<SIZE && getint(&int_array[n]) !=EOF; n++){
       printf("storing in n = %d, getint %d\n", n, int_array[n]);
    }

    for(s=0; s<n; s++)
        printf("%d \n",int_array[s]);

    return 0;
}