/*
 * Filename:    longlines.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        27-FEB-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 1-17, page 31
 *
 * Write a program to print all input lines that are longer than 80
 * characters.
 *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * I assumed the length of an input line is including the \n at the end.
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0
#define PRINTLEN 80

int get_line(char line[], int maxline);

int main(void)
{
    char line[PRINTLEN+1];    /* current input line */
    int len, longline;

    longline = FALSE;
    while ((len = get_line(line, PRINTLEN+1)) > 0) {
        if (line[len-1] != '\n') {
            /* line is longer that PRINTLEN chars */
            printf("%s", line);
            longline = TRUE;
        } else if (longline){
            /* print the rest of this long line */
            printf("%s", line);
            longline = FALSE;
        }
    }
    return EXIT_SUCCESS;
}

/* get_line:  read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
