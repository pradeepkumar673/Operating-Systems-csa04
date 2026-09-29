/* Create a new process by invoking the appropriate system call. Get the process identifier of the currently running process and its respective parent using system calls and display the same using a C program. */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t child_pid = fork();

    if (child_pid < 0) {
        perror("fork");
        return 1;
    }

    if (child_pid == 0) {
        printf("Child process ID: %ld\n", (long)getpid());
        printf("Parent process ID: %ld\n", (long)getppid());
    } else {
        printf("Parent process ID: %ld\n", (long)getpid());
        printf("Child process ID: %ld\n", (long)child_pid);
        waitpid(child_pid, NULL, 0);
    }

    return 0;
}
