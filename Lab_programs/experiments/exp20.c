/* Construct a C program to simulate Reader-Writer problem using Semaphores. */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t mutex,wblock; int readers=0,data=0;
void *reader(void*arg){sem_wait(&mutex);readers++;if(readers==1)sem_wait(&wblock);sem_post(&mutex);printf("Reader %ld reads: %d\n",(long)arg,data);sleep(1);sem_wait(&mutex);readers--;if(readers==0)sem_post(&wblock);sem_post(&mutex);return NULL;}
void *writer(void*arg){sem_wait(&wblock);data++;printf("Writer %ld writes: %d\n",(long)arg,data);sleep(1);sem_post(&wblock);return NULL;}
int main(){
    pthread_t r[3],w[2]; sem_init(&mutex,0,1);sem_init(&wblock,0,1);
    for(long i=0;i<2;i++)pthread_create(&w[i],NULL,writer,(void*)i);
    for(long i=0;i<3;i++)pthread_create(&r[i],NULL,reader,(void*)i);
    for(int i=0;i<2;i++)pthread_join(w[i],NULL);
    for(int i=0;i<3;i++)pthread_join(r[i],NULL);
    sem_destroy(&mutex);sem_destroy(&wblock);
    return 0;
}
