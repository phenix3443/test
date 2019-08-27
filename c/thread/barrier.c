// -*- coding:utf-8 -*-
// author:phenix3443
// desc: 屏障（barrier）使用示例

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *first_work (void *arg) {
    pthread_barrier_t *b = (pthread_barrier_t *)arg;
    unsigned int i = rand () % 1000 + 100;
    printf ("%lu sleep %d microseconds\n", pthread_self (), i);
    usleep (i);
    int res = pthread_barrier_wait (b);
    if (res == PTHREAD_BARRIER_SERIAL_THREAD) {
        printf ("%lu all thread done first work!\n", pthread_self ());
    }
    return ((void *)0);
}

int main (int argc, char *argv[]) {
    const int thread_num = 10;
    pthread_barrier_t b;
    pthread_barrier_init (&b, NULL, thread_num);
    pthread_t tids[thread_num];
    for (pthread_t tid = 0; tid < thread_num; tid++) {
        if (pthread_create (&tid, NULL, first_work, (void *)&b)) {
            printf ("create thread error");
            return 1;
        }
    }

    for (auto &tid : tids) {
        pthread_join (tid, NULL);
    }
    pthread_barrier_destroy (&b);
    return 0;
}
