#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 4) return 1;
    size_t bufsize = (size_t) atol(argv[3]);
    char *buf = malloc(bufsize);
    int in = open(argv[1], O_RDONLY);
    int out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    long reads = 0, writes = 0;
    ssize_t n;
    while ((n = read(in, buf, bufsize)) > 0) {
        reads++;
        write(out, buf, n);
        writes++;
    }
    reads++;
    close(in);
    close(out);
    free(buf);
    printf("buffer %zu bytes: %ld read() calls, %ld write() calls\n", bufsize, reads, writes);
    return 0;
}
