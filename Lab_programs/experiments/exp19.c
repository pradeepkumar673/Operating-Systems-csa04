/* Design a C program to implement process synchronization using mutex locks. */
#include <stdio.h>
#include <pthread.h>
int counter=0; pthread_mutex_t lock;
void *inc(void*arg){for(int i=0;i<5;i++){pthread_mutex_lock(&lock);counter++;printf("Thread %ld: counter=%d\n",(long)arg,counter);pthread_mutex_unlock(&lock);}return NULL;}
int main(){
    pthread_t t1,t2; pthread_mutex_init(&lock,NULL);
    pthread_create(&t1,NULL,inc,(void*)1L);pthread_create(&t2,NULL,inc,(void*)2L);
    pthread_join(t1,NULL);pthread_join(t2,NULL);
    printf("Final counter: %d\n",counter);pthread_mutex_destroy(&lock);
    return 0;
}
