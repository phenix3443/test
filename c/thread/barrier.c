// -*- coding:utf-8 -*-
// author:phenix3443
// desc: 屏障（barrier）使用示例

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *work (void *arg) {
    pthread_barrier_t *b = (pthread_barrier_t *)arg;
    unsigned int i = rand () % 1000 + 100;
    printf ("%lu sleep %d microseconds\n", pthread_self (), i);
    usleep (i);                 /* 模拟执行某种工作 */
    int res = pthread_barrier_wait (b);
    switch (res) {
    case PTHREAD_BARRIER_SERIAL_THREAD:
        printf ("all done, %lu be master!\n", pthread_self ());
        break;
    case 0:
        printf ("all done, %lu not master!\n", pthread_self ());
        break;
    default:
        printf ("all done, %lu unknown status!\n", pthread_self ());
    }
    return NULL;
}

int main (int argc, char *argv[]) {
    const int thread_num = 10;
    pthread_barrier_t b;
    pthread_barrier_init (&b, NULL, thread_num);
    pthread_t tids[thread_num];
    for (int i = 0; i< thread_num; i++) {
        if (pthread_create (&tids[i], NULL, work, (void *)&b)) {
            printf ("create thread error");
            return 1;
        }
    }

    for (int i = 0; i< thread_num; ++i) {
        pthread_join (tids[i], NULL);
    }

    pthread_barrier_destroy (&b);
    return 0;
}
