/* -*- coding:utf-8 -*- */
/* desc:读写锁 */

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

static int count = 0;
pthread_rwlock_t lock = PTHREAD_RWLOCK_INITIALIZER;

void *mywrite (void *arg) {
    for (int i = 0; i < 10; ++i) {
        pthread_rwlock_wrlock (&lock);
        ++count;
        printf ("write thread: %lu after add cout %d\n", pthread_self (),
                count);
        pthread_rwlock_unlock (&lock);
        usleep (10);
    }

    return ((void *)0);
}

/* read 读到的数据应该始终等于最近的mywrite输出 */
void *myread (void *arg) {
    for (int i = 0; i < 10; ++i) {
        pthread_rwlock_rdlock (&lock);
        printf ("read thread: %lu after add cout %d\n", pthread_self (),
                count);
        pthread_rwlock_unlock (&lock);
        usleep (10);  // 减少read时候打印数量
    }
    return ((void *)0);
}

int main (int argc, char *argv[]) {
    pthread_t w_id;             /* 读县城 */
    if (pthread_create (&w_id, NULL, mywrite, NULL)) {
        printf ("thread create error ");
        return -1;
    }

    const int thread_count = 3;
    pthread_t rids[thread_count];
    for (int i = 0; i < thread_count; ++i) {
        if (pthread_create (&rids[i], NULL, myread, NULL)) {
            printf ("thread create error ");
            return 2;
        }

        usleep (10);  // 让read线程执行
    }

    for (int i = 0; i < thread_count; ++i) {
        pthread_join (rids[i], NULL);
    }

    printf ("%d\n", count); /* 最终结果应该是250 */
    pthread_exit(NULL);

    return 0;
}
