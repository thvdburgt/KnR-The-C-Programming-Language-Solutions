/*
 * Filename:    strncpy.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        04-MAR-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 5-5, page 107
 *
 * Write versions of the library functions strncpy, strncat and strncmp,
 * which operate on at most the first n characters of their argument
 * strings. For example, strncpy(s,t,n) copies at most n characters of
 * t to s. Full descriptions are in Appendix B.
 */

#include <stdio.h>
#include <stdlib.h>

/* strncpy:  copy at most n characters of t to s */
void strncpy(char *s, const char *t, int n)
{
    while (*t && n-- > 0)
        *s++ = *t++;
    *s = '\0';
}

/* strcat:  concatenate at most n characters of t to the end of s; s
            must be big enough */
void strcat(char *s, const char *t, int n)
{
    while (*s)       /* find end of s */
        s++;
    while (*t && n-- > 0)
        *s++ = *t++;
    *s = '\0';
}

/* strncmp:  compare at most n characters of s and t, return <0 if s<t,
             0 if s==t, >0 if s>t */
int strncmp(char *s, const char *t, int n)
{
    for (; *s == *t && n-- > 0; s++, t++)
        if (*s == '\0' || n == 0)
            return 0;
    return *s - *t;
}
