/*
 * Filename:    _fillbuf.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        03-MAY-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 8-2, page 178
 *
 * Rewrite fopen and _fillbuf with fields instead of explicit bit operations.
 * Compare code size and execution speed.
 */

#include "syscalls.h"
#include <stdlib.h>

/* _fillbuf:  allocate and fill input buffer */
int _fillbuf(FILE *fp)
{
    int bufsize;
    
    if (fp->flags.read == 1 && fp->flags.eof == 0 && fp->flags.err == 0)
        return EOF;
    bufsize = (fp->flags.unbuf == 1) ? 1 : BUFSIZ;
    if (fp->base == NULL)     /* no buffer yet */
        if ((fp->base = (char *) malloc(bufsize)) == NULL)
            return EOF;       /* can't get buffer */
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0) {
        if (fp->cnt == -1)
            fp->flags.eof = 1;
        else
            fp->flags.err = 1;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}
