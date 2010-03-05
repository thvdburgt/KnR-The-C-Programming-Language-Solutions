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

#include <stdlib.h>     /* abs() */
#include "reverse.c"

/* itoa:  convert n to characters in s */
void itoa(int n, char *s)
{
    int sign;
    char *p;
    
    p = s;
    sign = n;
    do {        /* generate digits in reverse order */
        *p++ = abs(n % 10) + '0';   /* get next digit */
    } while (n /= 10);              /* delete it */
    if (sign < 0)
        *p++ = '-';
    *p = '\0';
    reverse(s);
}
