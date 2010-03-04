/*
 * Filename:    escape.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        24-FEB-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 3-2, page 60
 *
 * Write a function escape(s,t) that converts characters like newline
 * and tab into visible escape sequences like \n and \t as it copies the
 * string t to s. Use a switch. Write a function for the other direction
 * as well, converting escape sequences into the real characters. 
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

/* escape:  converts newlines and tabs into visible escape sequenes as
            it copies the string t into s */
void escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; ++i) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
            }
    }
    s[j] = '\0';
}

/* unescape:  converts escape sequenes '\n' and '\t' into newlines and
              tabs into as it copies the string t into s */
void unescape(char s[], char t[])
{
    int i, j;
    int slash;

    slash = FALSE;
    for (i = j = 0; t[i] != '\0'; ++i) {
        switch (t[i]) {
            case '\\':
                slash = TRUE;
                break;
            case 'n':
                if (slash) {
                    s[j++] = '\n';
                    slash = FALSE;
                    break;
                }
            case 't':
                if (slash) {
                    s[j++] = '\t';
                    slash = FALSE;
                    break;
                }
            default:
                s[j++] = t[i];
                break;
            }
    }
    s[j] = '\0';
}

int main(void)
{
    int i;
    char c, s[1024], t[1024];
    
    i = 0;
    while ((c = getchar()) != EOF)
        t[i++] = c;
   t[i] = '\0';
    
    printf(">%s\n", t);
    escape(s, t);
    printf(">%s\n", s);
    unescape(t, s);
    printf(">%s\n", t);
    
    return EXIT_SUCCESS;
}

