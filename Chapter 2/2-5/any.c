/*
 * Filename:    any.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        23-FEB-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 2-5, page 48
 *
 * Write the function any(s1,s2), which returns the first location in
 * the string s1 where any character from the string s2 occurs, or -1 if
 * s1 contains no characters from s2. (The standard library function
 * strpbrk does the same job but returns a pointer to the location.) 
 */

#include <stdio.h>
#include <stdlib.h>

int any(char s1[], char s2[]);

int main(void)
{
    char s1[] = "abcdef";
    char s2[] = "def";
    printf("%d\n", any(s1, s2));

    return EXIT_SUCCESS;
}

/* any:  returns the first location in s1 where any character from s2
         occurs, or -1 if s1 contains no characters from s2. */
int any(char s1[], char s2[])
{
    int i, k;

    for (i = 0; s1[i] != '\0'; i++)
        for (k = 0; s2[k] != '\0'; k++)
            if (s1[i] == s2[k])
                return i;
    return -1; /* s1 contains no characters from s2 */
}
