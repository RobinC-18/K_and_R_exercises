#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXOP   100         /* max size of operand or operator */
#define MAXVAL  100         /* maximum depth of val stack */
#define BUFSIZE 100         /* buffer size */
#define NUMBER '0'          /* signal that a number was found */

int sp = 0;                 /* next free stack position */
double val[MAXVAL];         /* value stack */
char buf[BUFSIZE];
int bufp = 0;

int getop(char []);
int getch(void);
void ungetch(int);
void push(double);
double pop(void);

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

/* getop: get next operator or numeric operand */
int getop(char s[]) 
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    if (isdigit(c) || c == '-')
    {
        while(isdigit(s[++i] = c = getch()))
            ;
    }
    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    if (strcmp(s, "-") == 0)
        return '-';
    return NUMBER;
}

void push(double f)
{
    // printf("Value of sp: %d \n", sp);
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else 
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* reverse Polish calculator */

int main(int argc, char *argv[]) {
    int type;
    double op1, op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case 'p':
            printf("first: %g, second: %g\n", val[sp - 1], val[sp - 2]);
            break;
        case 'd':
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 's':
            op1 = pop();
            op2 = pop();
            push(op1);
            push(op2);
            break;
        case 'c':
            sp = 0;
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push((int)pop() % (int)op2);
            else
                printf("error: can't mod with 0\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}