/*
 * Answer to Exercise 3-2, page 60
 *
 * Write a function escape(s,t) that converts characters like newline
 * and tab into visible escape sequences like \n and \t as it copies the
 * string t to s. Use a switch. Write a function for the other direction
 * as well, converting escape sequences into the real characters. 
 */

#include <stdio.h>
#define TRUE  1
#define FALSE 0

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

main()
{
    return 0;
}

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

