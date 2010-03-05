/*
 * Filename:    itoa.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        24-FEB-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 3-4, page 64
 *
 * In a two's complement number representation, our version of itoa does
 * not handle the largest negative number, that is, the value of n equal
 * to -(2^(wordsize - 1)). Explain why not. Modify it to print that
 * value correctly regardless of the machine on which it runs.
 *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * It does not handle the largest negative number because it does not
 * have a positive equivalent; -n where n is the largest negative number
 * gives n; because n is still negative n%10 gives negative values
 * instead of the desired positive ones. If we take the asbolute value
 * of n%10 we get the correct value and character.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void)
{
    int n = INT_MIN;
    char s[16];

    itoa(1337, s);
    printf("%s\n", s);
    itoa(n, s);
    printf("%s\n", s);
    
    return EXIT_SUCCESS;
}

/* itoa:  convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;

    sign = n;
    i = 0;
    do {        /* generate digits in reverse order */
        s[i++] = abs(n % 10) + '0';     /* get next digit */
    } while (n /= 10);                  /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* reverse:  reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
