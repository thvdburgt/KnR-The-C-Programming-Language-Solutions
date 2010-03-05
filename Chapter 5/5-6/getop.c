/*
 * Filename:    itoa.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        04-MAR-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 5-6, page 107
 *
 * Rewrite appropriate programs from earlier chapters and exercises with
 * pointers instead of array indexing. Good possibilities include
 * getline (Chapters 1 and 4), atoi, itoa, and their variants
 * (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop
 * (Chapter 4). 
 */

#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'  /* signal that a number was found */

int getch(void);
void ungetch(int);

/* getop:  get next operator or numeric operand */
int getop(char *s)
{
    char c;
    
    while ((*s = c = getch()) == ' ' || c == '\t');
    *++s = '\0';
    if (!isdigit(c) && c != '.')
        return c;       /* not a number */
    --s;                /* remove the \0 */
    if (isdigit(c))     /* collect intiger part */
        while (isdigit(*++s = c = getch()));
    if (c == '.')       /* collect fraction part */
        while (isdigit(*++s = c = getch()));
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int  bufp = 0;      /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
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
