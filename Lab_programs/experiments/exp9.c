/* Illustrate the concept of inter-process communication using shared memory with a C program. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHM_SIZE 1024
int main() {
    key_t key = ftok("shmfile",65);
    int shmid = shmget(key,SHM_SIZE,IPC_CREAT|0666);
    if(shmid==-1){perror("shmget");exit(1);}
    char *shm = (char*)shmat(shmid,NULL,0);
    strcpy(shm,"Hello, shared memory!");
    printf("Written: %s\n",shm);
    shmdt(shm);
    shm=(char*)shmat(shmid,NULL,0);
    printf("Read:    %s\n",shm);
    shmdt(shm);
    shmctl(shmid,IPC_RMID,NULL);
    return 0;
}
