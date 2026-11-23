/* Design a C program to simulate the concept of Dining-Philosophers problem. */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define N 5
sem_t chopstick[N];
void *philosopher(void *arg){
    int id=*(int*)arg;
    printf("Philosopher %d thinking\n",id);sleep(1);
    sem_wait(&chopstick[id]);
    sem_wait(&chopstick[(id+1)%N]);
    printf("Philosopher %d eating\n",id);sleep(1);
    sem_post(&chopstick[(id+1)%N]);
    sem_post(&chopstick[id]);
    printf("Philosopher %d done\n",id);
    return NULL;
}
int main(){
    pthread_t tid[N]; int ids[N];
    for(int i=0;i<N;i++) sem_init(&chopstick[i],0,1);
    for(int i=0;i<N;i++){ids[i]=i;pthread_create(&tid[i],NULL,philosopher,&ids[i]);}
    for(int i=0;i<N;i++) pthread_join(tid[i],NULL);
    for(int i=0;i<N;i++) sem_destroy(&chopstick[i]);
    return 0;
}
