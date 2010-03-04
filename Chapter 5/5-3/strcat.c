/*
 * Filename:    strcat.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        04-MAR-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 5-3, page 107
 *
 * Write a pointer version of the function strcat that we showed in
 * Chapter 2: strcat(s,t) copies the string t to the end of s.
 */

#include <stdio.h>
#include <stdlib.h>

/* strcat:  concatenate t to end of s; s must be big enough */
void strcat(char *s, const char *t)
{
    while (*s)      /* find end of s */
        s++;
    while (*t)      /* copy t */
        *s++ = *t++;
    *s = '\0';
}

int main(void)
{
    char s[100] = "ab\0c";
    char t[100] = "def";
    strcat(s, t);
    puts(s);
    return EXIT_SUCCESS;
}
