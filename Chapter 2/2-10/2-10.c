/*
 * Answer to Exercise 2-10, page 52
 *
 * Rewrite the function lower, which converts upper case letters to
 * lower case, with a conditional expression instead of if-else . 
 */

#include <stdio.h>

int lower(int c);

main()
{
    putchar(lower('R'));
    putchar('\n');

    return 0;
}

/* lower:  convert c to lower case; ASCII only */
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}

