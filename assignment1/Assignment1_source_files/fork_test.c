#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

static long pss_kb(pid_t pid)
{
    char path[64], line[256];
    long v = 0;
    snprintf(path, sizeof path, "/proc/%d/smaps_rollup", (int) pid);
    FILE *f = fopen(path, "r");
    if (!f) return 0;
    while (fgets(line, sizeof line, f))
        if (strncmp(line, "Pss:", 4) == 0) sscanf(line + 4, "%ld", &v);
    fclose(f);
    return v;
}

int main(int argc, char *argv[])
{
    int n = 1000;
    if (argc > 1 && strcmp(argv[1], "mem") == 0) {
        int fds[2];
        pid_t pids[1000];
        pipe(fds);
        for (int i = 0; i < n; i++) {
            pids[i] = fork();
            if (pids[i] == 0) {
                char c;
                close(fds[1]);
                read(fds[0], &c, 1);
                _exit(0);
            }
        }
        nanosleep(&(struct timespec){0, 300000000}, NULL);
        long total = pss_kb(getpid());
        for (int i = 0; i < n; i++) total += pss_kb(pids[i]);
        close(fds[1]);
        for (int i = 0; i < n; i++) waitpid(pids[i], NULL, 0);
        printf("1000 processes alive, total memory used: %ld KB\n", total);
        return 0;
    }
    struct timespec a, b;
    clock_gettime(CLOCK_MONOTONIC, &a);
    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        if (pid == 0) _exit(0);
    }
    for (int i = 0; i < n; i++) wait(NULL);
    clock_gettime(CLOCK_MONOTONIC, &b);
    printf("created 1000 processes in %.2f ms\n",
           (b.tv_sec - a.tv_sec) * 1000.0 + (b.tv_nsec - a.tv_nsec) / 1e6);
    return 0;
}
