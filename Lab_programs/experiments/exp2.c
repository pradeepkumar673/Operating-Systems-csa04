/* Identify the system calls to copy the content of one file to another and illustrate the same using a C program. */
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int source_fd;
    int destination_fd;
    char buffer[4096];
    ssize_t bytes_read;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    source_fd = open(argv[1], O_RDONLY);
    if (source_fd < 0) {
        perror("open source");
        return 1;
    }

    destination_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (destination_fd < 0) {
        perror("open destination");
        close(source_fd);
        return 1;
    }

    while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0) {
        ssize_t total_written = 0;
        while (total_written < bytes_read) {
            ssize_t bytes_written = write(destination_fd, buffer + total_written,
                                          (size_t)(bytes_read - total_written));
            if (bytes_written < 0) {
                if (errno == EINTR)
                    continue;
                perror("write");
                close(source_fd);
                close(destination_fd);
                return 1;
            }
            total_written += bytes_written;
        }
    }

    if (bytes_read < 0) {
        perror("read");
        close(source_fd);
        close(destination_fd);
        return 1;
    }

    if (close(source_fd) < 0 || close(destination_fd) < 0) {
        perror("close");
        return 1;
    }

    printf("Contents copied from %s to %s\n", argv[1], argv[2]);
    return 0;
}
