#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  /* File Control Operations */
#include <unistd.h> /* Symbolic Constants */

/* cat:  concatenate files */
int main(int argc, char *argv[])
{
    int fd;
    void filecopy(int ifd, int ofd);
    char *prog = argv[0];   /* program name for errors */

    if (argc == 1) /* no args; copy standard input */
        filecopy(0, 1);
    else
        while (--argc > 0)
            if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            } else {
                filecopy(fd, 1);
                close(fd);
            }
    exit(EXIT_SUCCESS);
}

/* filecopy:  copy file ifd to file ofd */
void filecopy(int ifd, int ofd)
{
    char buf[BUFSIZ];
    int c;

    while ((c = read(ifd, buf, BUFSIZ)) > 0)  /* read from ifd */
        write (ofd, buf, c);                  /* write to ofd */
}
