/* -*-coding:utf-8;-*- */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "thpool.h"
void work1 (void *data) {
    printf ("%lu work 1, count=%d\n", pthread_self (), *(int *)data);
    usleep (100);
}

void work2 (void *data) {
    printf ("%lu work 2, count=%d\n", pthread_self (), *(int *)data);
    usleep (100);
}

int main (int argc, char *argv[]) {
    threadpool tp = thpool_init (2);
    for (volatile int i = 0; i < 5; ++i) {
        int *k = (int *)malloc (sizeof (i));
        thpool_add_work (tp, work1, (void *)&k);
        thpool_add_work (tp, work2, (void *)&k);
    }
    thpool_wait (tp);
    thpool_destroy (tp);
    return 0;
}
