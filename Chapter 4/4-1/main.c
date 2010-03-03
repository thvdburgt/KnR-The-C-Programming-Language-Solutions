/*
 * Answer to Exercise 3-6, page 64
 *
 * Write the function strrindex(s,t), which returns the position of the
 * rightmost occurrence of t in s, or -1 if there is none. 
 */

#include <stdio.h>
#define MAXLINE 1000

int get_line(char s[], int lim);
int strrindex(char s[], char t[]);

char pattern[] = "ould";

int main(void)
{
    char line[MAXLINE];
    int found = 0;
    int rindex;
    
    while (get_line(line, MAXLINE) > 0) {
        rindex = strrindex(line, pattern);
        if (rindex >= 0) {
            printf("%3d - %s", rindex, line);
            found++;
        }
    }
    printf("total of %d found\n", found);
    return 0;
}

