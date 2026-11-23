/* Write C programs to demonstrate the following thread related concepts: create, join, equal, exit. */
#include <stdio.h>
#include <pthread.h>
void *body(void*arg){printf("Thread %ld running\n",(long)arg);pthread_exit((void*)((long)arg*10));}
int main(){
    pthread_t t1,t2;
    pthread_create(&t1,NULL,body,(void*)1L);
    pthread_create(&t2,NULL,body,(void*)2L);
    if(pthread_equal(t1,t2))printf("Equal\n");else printf("Not equal\n");
    void*r1,*r2;
    pthread_join(t1,&r1);pthread_join(t2,&r2);
    printf("T1 exit: %ld, T2 exit: %ld\n",(long)r1,(long)r2);
    return 0;
}
