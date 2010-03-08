/*
 * Filename:    atof.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        08-MAR-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 4-2, page 73
 *
 * Extend atof to handle scientific notation of the form 123.45e-6 
 * where a floating-point number may be followed by e or E and an
 * optionally signed exponent.
 */

#include <ctype.h>  /* isspace() & isdigit() */
#include <math.h>   /* pow() */

/* atof:  convert string s to double */
float atof(char s[])
{
    double val, power, exp;
    int i, sign, esign;

    for (i = 0; isspace(s[i]); i++)  /* skip white space */
        ;
    sign = (s[i] =='-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)     /* integer */
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.') {                      /* fraction */
        i++;
        for (power = 1.0; isdigit(s[i]); i++) {
            val = 10.0 * val + (s[i] - '0');
            power *= 10.0;
        }
        val *= sign / power;
    }
    if (s[i] == 'e' || s[i] == 'E') {       /* exponent*/
        esign = (s[++i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exp = 0.0; isdigit(s[i]); i++)
            exp = 10.0 * exp + (s[i] - '0');
        val *= pow(10, esign * exp);
    }
    return val;
}
