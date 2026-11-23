/* Write a C program to simulate the solution of Classical Process Synchronization Problem. */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t sem; int shared=0;
void *process(void*arg){int id=*(int*)arg;sem_wait(&sem);printf("P%d enters CS. shared=%d\n",id,++shared);sleep(1);printf("P%d leaves CS.\n",id);sem_post(&sem);return NULL;}
int main(){
    int n; printf("Processes: ");scanf("%d",&n);
    pthread_t tid[20];int ids[20];sem_init(&sem,0,1);
    for(int i=0;i<n;i++){ids[i]=i+1;pthread_create(&tid[i],NULL,process,&ids[i]);}
    for(int i=0;i<n;i++)pthread_join(tid[i],NULL);
    sem_destroy(&sem);return 0;
}
