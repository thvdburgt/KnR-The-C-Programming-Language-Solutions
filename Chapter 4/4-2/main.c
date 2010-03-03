/*
 * Answer to Exercise 4-2, page 73
 *
 * Extend atof to handle scientific notation of the form 123.45e-6 
 * where a floating-point number may be followed by e or E and an
 * optionally signed exponent.
 */

#include <stdio.h>

double atof(char s[]);

int main(void)
{
    printf("%g\n", atof("123.45e-2"));
    
    return 0;
}

