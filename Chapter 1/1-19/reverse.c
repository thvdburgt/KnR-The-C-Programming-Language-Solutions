/*
 * Filename:    reverse.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        27-FEB-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 1-19, page 31
 *
 * Write a function reverse(s) that reverses the character string s. Use
 * it to write a program that reverses its input a line at a time.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
void reverse(char s[]);

int main(void)
{
    int len;            /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s", line);
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

/* reverse:  reverses the character string s */
void reverse(char s[])
{
    int i, l;
    char temp;

    /* get length of string */
    for (l = 0; s[l] != '\0'; ++l)
        ;
    /* skip \n at the end of the line */
    l--;

    for (i = 0; i < l; ++i) {
        temp = s[i];
        s[i] = s[l-1];
        s[l-1] = temp;
        --l;
    }
}
