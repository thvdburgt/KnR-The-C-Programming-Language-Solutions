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

#include <string.h>

/* reverse:  reverse string s in place */
void reverse(char *s)
{
    char tmp, *p;
    p = s + strlen(s) - 1;
    while (p > s) {
        tmp = *s;
        *s++ = *p;
        *p-- = tmp;
    }
}
