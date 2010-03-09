/*
 * Filename:    polishcalc.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        08-MAR-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 4-5, page 79
 *
 * Add access to library functions like sin, exp, and pow. See <math.h>
 * in Appendix B, Section 4.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>     /* strcmp */
#include <math.h>       /* sin, exp & pow */

#define MAXOP   100     /* max size of operand or operator */
#define NUMBER  '0'     /* signal that a number was found */
#define LIBFUNC '1'     /* signal that a library function was found */

void dofunc(char []);
int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case LIBFUNC:
            dofunc(s);
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
                printf("error: zero devisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return EXIT_SUCCESS;
}

/* dofunc:  execute the function in s, push answer. */
void dofunc(char s[])
{
    double op1, op2;
    if (strcmp(s, "sin") == 0)          /* sine*/
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)     /* cosine */
        push(cos(pop()));
    else if (strcmp(s, "tan") == 0)     /* tangent */
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)     /* exponential function */
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0) {   /* x to the power of y */
        op2 = pop();
        op1 = pop();
        if (op1 == 0 && op2 <= 0)
             printf("error: domain (%g^%g)\n", op1, op2);
        else
            push(pow(pop(), op2));
    } else {
        printf("error: unknown command %s\n", s);
    }
}

#define MAXVAL  100  /* maximum depth of val stack*/

int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */

/* push:  push f onto stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}


/* pop:  pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop:  get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    i = 0;
    if (isalpha(c)) {
        while (isalpha(s[++i] = c = getch()));
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        return LIBFUNC;
    }
    if (!isdigit(c) && c != '.' && c != '-')
        return c;                       /* not a number */
    if (isdigit(c) || c == '-')         /* collect integer part */
        while (isdigit(s[++i] = c = getch()));
    if (c == '.')                       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';                        /* terminate string */
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int  bufp = 0;      /* next free position in buf */

int getch(void)     /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
