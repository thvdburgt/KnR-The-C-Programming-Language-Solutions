/*
 * Filename:    getfloat.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        01-MAR-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 5-2, page 97
 *
 * Write getfloat, the floating-point analog of getint. What type does
 * getfloat return as its function value?
 *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * The function returns an int
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include "getch.h"

/* getfloat:  get next float from input into *pn */
int getfloat(float *pn)
{
    double power;
    int c, sign, exp, esign, bigE;

    while (isspace(c = getch()))   /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);    /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) { /* + or - not followed by a digit */
            ungetch(c);                          /* ungetch non-digit */
            ungetch(sign == 1 ? '+' : '-');      /* ungetch + or - */
            return 0;
        }
    }
    for (*pn = 0.0; isdigit(c); c = getch())     /* integer part */
        *pn = 10.0 * *pn + (c - '0');
    if (c == '.')
        c = getchar();
    for (power = 1.0; isdigit(c); c = getch()) { /* fractional part */
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;
    }
    bigE = (c == 'E') ? 1 : 0;
    if (c == 'e' || c == 'E') {
        c = getch();
        esign = (c == '-') ? -1 : 1;
        if (c == '+' || c == '-') {
            c = getch();
            if (!isdigit(c)) { /* + or - not followed by a digit */
                ungetch(c);
                ungetch(sign == 1 ? '+' : '-');
            }
        } else if (!isdigit(c)) { /* e or E not followed by an int */
            ungetch(c);
            ungetch(bigE == 0 ? 'e' : 'E');
        }
        for (exp = 0; isdigit(c); c = getch()) /* exponent part */
            exp = 10 * exp + (c - '0');
        *pn *= (sign / power) * pow(10, esign * exp);
    } else {
        *pn *= (sign / power);
    }
    if (c != EOF)
        ungetch(c);
    return c;
}

/* sample implementation of getfloat */
int main(void)
{
    float f;
    int r;

    r = getfloat(&f);
    if (r > 0)
        printf("(%c) %g\n", r, f);
    else if (r == 0)
        printf("not a number\n");
    else if (r == EOF)
        printf("end of file\n");
    else
        printf("wtf happend?\n");
    return EXIT_SUCCESS;
}
