/* Illustrate the concept of multithreading using a C program. */
#include <stdio.h>
#include <pthread.h>
void *func1(void *a){printf("Thread 1 running\n");return NULL;}
void *func2(void *a){printf("Thread 2 running\n");return NULL;}
int main() {
    pthread_t t1,t2;
    pthread_create(&t1,NULL,func1,NULL);
    pthread_create(&t2,NULL,func2,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("Both threads done.\n");
    return 0;
}
