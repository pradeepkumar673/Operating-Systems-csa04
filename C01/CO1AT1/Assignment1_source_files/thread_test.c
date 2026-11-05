#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

static int release = 0;
static pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t c = PTHREAD_COND_INITIALIZER;

static void *quick(void *arg)
{
    (void) arg;
    return NULL;
}

static void *hold(void *arg)
{
    (void) arg;
    pthread_mutex_lock(&m);
    while (!release) pthread_cond_wait(&c, &m);
    pthread_mutex_unlock(&m);
    return NULL;
}

static long pss_kb(void)
{
    char line[256];
    long v = 0;
    FILE *f = fopen("/proc/self/smaps_rollup", "r");
    if (!f) return 0;
    while (fgets(line, sizeof line, f))
        if (strncmp(line, "Pss:", 4) == 0) sscanf(line + 4, "%ld", &v);
    fclose(f);
    return v;
}

int main(int argc, char *argv[])
{
    int n = 1000;
    pthread_t t[1000];
    if (argc > 1 && strcmp(argv[1], "mem") == 0) {
        for (int i = 0; i < n; i++) pthread_create(&t[i], NULL, hold, NULL);
        nanosleep(&(struct timespec){0, 300000000}, NULL);
        long total = pss_kb();
        pthread_mutex_lock(&m);
        release = 1;
        pthread_cond_broadcast(&c);
        pthread_mutex_unlock(&m);
        for (int i = 0; i < n; i++) pthread_join(t[i], NULL);
        printf("1000 threads alive, total memory used: %ld KB\n", total);
        return 0;
    }
    struct timespec a, b;
    clock_gettime(CLOCK_MONOTONIC, &a);
    for (int i = 0; i < n; i++) pthread_create(&t[i], NULL, quick, NULL);
    for (int i = 0; i < n; i++) pthread_join(t[i], NULL);
    clock_gettime(CLOCK_MONOTONIC, &b);
    printf("created 1000 threads in %.2f ms\n",
           (b.tv_sec - a.tv_sec) * 1000.0 + (b.tv_nsec - a.tv_nsec) / 1e6);
    return 0;
}
