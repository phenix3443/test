// -*- coding:utf-8 -*-
// author:phenix3443
// desc:模拟线程的竞争情形
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static int count = 0;

void *work (void *arg) {
    for (int i = 0; i < 50; ++i) {
        ++count;
        usleep (1000);
    }

    return ((void *)0);
}

int main (int argc, char *argv[]) {
    const int thread_count = 5;
    pthread_t tids[thread_count];

    for (int i = 0; i < thread_count; ++i) {
        if (pthread_create (&tids[i], NULL, work, NULL)) {
            printf ("thread create error ");
            return -1;
        }
    }
    for (int i = 0; i < thread_count; ++i) {
        pthread_join (tids[i], NULL);
    }
    printf ("%d\n", count); /* 最终结果应该是250，但是每次数字不一样 */

    return 0;
}
