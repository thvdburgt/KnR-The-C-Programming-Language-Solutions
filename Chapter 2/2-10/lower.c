/*
 * Filename:    rightrot.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        23-FEB-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 2-9, page 51
 *
 * Rewrite the function lower, which converts upper case letters to
 * lower case, with a conditional expression instead of if-else. 
 */

#include <stdio.h>
#include <stdlib.h>

int lower(int c);

int main(void)
{
    putchar(lower('R'));
    putchar('\n');
    return EXIT_SUCCESS;
}

/* lower:  convert c to lower case; ASCII only */
int lower(int c)
{
    return ('A' <= c && c <= 'Z') ? c - 'A' + 'a' : c;
}
