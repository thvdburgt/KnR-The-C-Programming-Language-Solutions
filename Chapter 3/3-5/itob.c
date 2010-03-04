/*
 * Filename:    itob.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        24-FEB-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 3-5, page 64
 *
 * Write the function itob(n,s,b) that converts the integer n into a
 * base b character representation in the string s. In particular,
 * itob(n,s,16) formats n as a hexadecimal integer in s.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
    char s[64];
    itob(-255, s, 8);
    printf("%s\n", s);

    return EXIT_SUCCESS;
}

/* itob:  comvert n to characters in base b in s */
void itob(int n, char s[], int b)
{
    int i, sign;
    char symbols[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    if (2 > b || b > strlen(symbols) )
        return;     /* not a valid base */
    
    sign = n;
    i = 0;
    do {            /* generate symbols in reverse order */
        s[i++] = symbols[abs(n % b)];   /* get next symbols */
    } while (n /= b);                   /* delete it */
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

