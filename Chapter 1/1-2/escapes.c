/*
 * Filename:    escapes.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        25-FEB-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 1-2, page 8
 *
 * Experiment to find out what happens when printf's argument string
 * contains \c, where c is some character not listed above.
 *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * The following are legal escape sequences:
 * (description, ASCII char, escape sequense, decimal ASCII code)
 *
 * audible alert (bell)    BEL   \a      7
 * backspace               BS    \b      8
 * horizontal tab          HT    \t      9
 * newline                 LF    \n     10
 * vertical tab            VT    \v     11
 * formfeed                FF    \f     12
 * carriage return         CR    \r     13
 * double quote            "     \"     34
 * single quote            '     \'     39
 * question mark           ?     \?     63
 * backslash               \     \\     92
 * octal number            ooo   \ooo
 * hexadecimal number      hh    \xhh
 *
 * Using a non-specified escape sequence invokes undefined behaviour
 * (behavior, upon use of a nonportable or erroneous program construct
 * or of erroneous data, for which this International Standard imposes
 * no requirements).
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* legal escape sequences */
    printf("audible alert (bell) BEL   \\a     %d\n" , '\a');
    printf("backspace            BS    \\b     %d\n" , '\b');
    printf("horizontal tab       HT    \\t     %d\n" , '\t');
    printf("newline              LF    \\n    %d\n"  , '\n');
    printf("vertical tab         VT    \\v    %d\n"  , '\v');
    printf("formfeed             FF    \\f    %d\n"  , '\f');
    printf("carriage return      CR    \\r    %d\n"  , '\r');
    printf("double quote         \"     \\\"    %d\n", '\"');
    printf("single quote         \'     \\\'    %d\n", '\'');
    printf("question mark        ?     \\?    %d\n"  , '\?');
    printf("backslash            \\     \\\\    %d\n", '\\');
    printf("\n");
    printf("forty-two in octal   0%o   \\52   %d\n"  , '\52' , '\52');
    printf("forty-two in hex     0x%X  \\x2A  %d\n"  , '\x2A', '\x2A');
    printf("\n");
    /* illegal escape sequence */
    printf("invalid escape sequence    \\c    %d (%c)\n" , '\c', '\c');
    return EXIT_SUCCESS;
}
