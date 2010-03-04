/*
 * Filename:    expand.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        24-FEB-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 3-3, page 63
 *
 * Write a function expand(s1,s2) that expands shorthand notations like
 * a-z in the string s1 into the equivalent complete list abc...xyz in
 * s2. Allow for letters of either case and digits, and be prepared to
 * handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading
 * or trailing - is taken literally.
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void expand(char s1[], char s2[]);
int validrange(char c1, char c2);

int main(void)
{
    char s1[512] = "-a-z 0-9 a-d-f -0-2 some text 1-1 WITH CAPITALS! 0-0 5-3 -";
    char s2[512];
    expand(s1, s2);
    printf("%s\n", s2);
    
    return EXIT_SUCCESS;
}

/* expand:  expands shorthand notations in the string s1 into the
            equivalent complete list in s2 */
void expand(char s1[], char s2[])
{
    int i, j;
    char tmp;
    int dash;

    dash = 0;
    for (i = j = 0; s1[i] != '\0'; ++i) {
        if (s1[i] == '-') {
            if (i == 0 || s1[i+1] == '\0') {
                /* '-' is leading or trailing, so just copy it. */
                s2[j++] = s1[i];
            } else {
                /* check if this is a valid range. */
                if (validrange(s1[i-1], s1[i+1])) {
                    while (s2[j-1] < s1[i+1]) {
                        s2[j] = s2[j-1] + 1;
                        j++;
                    }
                    /* skip next character we already printed it. */
                    ++i;
                } else {
                    s2[j++] = s1[i];
                }
            }
        } else {
            s2[j++] = s1[i];
        }
    }
    /* End the string with a NUL byte */
    s2[j] = '\0';
}

/* validrange:  returns non-zero if c1-c2 is a valid range. */
int validrange(char c1, char c2)
{
    if (('a' <= c1 && c1 <= 'z') && /* valid range in a-z */
        (c1  <= c2 && c2 <= 'z'))
        return TRUE;
    if (('A' <= c1 && c1 <= 'Z') && /* valid range in A-Z */
        (c1  <= c2 && c2 <= 'Z'))
        return TRUE;
    if (('0' <= c1 && c1 <= '9') && /* valid range in 0-9 */
        (c1  <= c2 && c2 <= '9'))
        return TRUE;
    
    return FALSE;   /* not a valid range */
}
