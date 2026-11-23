#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int status;
    pid_t pid;
    printf("shell: running job 1\n");
    fflush(stdout);
    pid = fork();
    if (pid == 0) {
        execlp("expr", "expr", "6", "*", "7", (char *) NULL);
        exit(127);
    }
    waitpid(pid, &status, 0);
    printf("job 1 exit status %d\n", WEXITSTATUS(status));
    printf("shell: running job 2\n");
    fflush(stdout);
    pid = fork();
    if (pid == 0) exit(3);
    waitpid(pid, &status, 0);
    printf("job 2 exit status %d\n", WEXITSTATUS(status));
    return 0;
}
