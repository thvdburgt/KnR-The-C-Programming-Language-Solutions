/*
 * Filename:    polishcalc.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        08-MAR-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 4-4, page 79
 *
 * Add commands to print the top element of the stack without popping,
 * to duplicate it, and to swap the top two elements. Add a command to
 * clear the stack.
 *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * I added the following functions:
 *  - void show_top(void);
 *  - void duplicate_top(void);
 *  - void swap_top(void);
 *  - void clear(void);
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXOP   100   /* max size of operand or operator */
#define NUMBER  '0'   /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
void show_top(void);
void duplicate_top(void);
void swap_top(void);
void clear(void);

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
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
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

/* show_top:  prints the top element of the stack without popping */
void show_top(void)
{
    if (sp > 0)
        printf("top element of stack: %g\n", val[sp-1]);
    else
        printf("error: stack empty\n");
}

/* duplicate:  duplicates the top element of the stack */
void duplicate_top(void)
{
    double tmp = pop();
    push(tmp);
    push(tmp);
}

/* swap:  swap the two top elements of the stack */
void swap_top(void)
{
    double tmp1 = pop();
    double tmp2 = pop();
    push(tmp1);
    push(tmp2); 
}

/* clear:  clear the stack */
void clear(void)
{
    sp = 0;
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
    if (!isdigit(c) && c != '.' && c != '-')
        return c;                       /* not a number */
    i = 0;
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
