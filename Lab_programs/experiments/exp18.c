/* Construct a C program to simulate producer-consumer problem using semaphores. */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define BUF 5
int buffer[BUF],in=0,out=0;
sem_t empty,full; pthread_mutex_t lock;
void *producer(void*a){for(int i=1;i<=5;i++){sem_wait(&empty);pthread_mutex_lock(&lock);buffer[in]=i;printf("Produced: %d\n",i);in=(in+1)%BUF;pthread_mutex_unlock(&lock);sem_post(&full);sleep(1);}return NULL;}
void *consumer(void*a){for(int i=1;i<=5;i++){sem_wait(&full);pthread_mutex_lock(&lock);int v=buffer[out];printf("Consumed: %d\n",v);out=(out+1)%BUF;pthread_mutex_unlock(&lock);sem_post(&empty);sleep(2);}return NULL;}
int main(){
    pthread_t p,c;
    sem_init(&empty,0,BUF);sem_init(&full,0,0);pthread_mutex_init(&lock,NULL);
    pthread_create(&p,NULL,producer,NULL);pthread_create(&c,NULL,consumer,NULL);
    pthread_join(p,NULL);pthread_join(c,NULL);
    sem_destroy(&empty);sem_destroy(&full);pthread_mutex_destroy(&lock);
    return 0;
}
