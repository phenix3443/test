/* -*- coding:utf-8 -*- */
/* desc:使用条件变量模拟生产者和消费这问题 */
/* 1. 生产者和消费这共享缓冲区。 */
/* 2. 不允许消费者到一个空的缓冲区中取产品 */
/* 3. 不允许生产者向一个已经装满产品且尚未被取走的缓冲区中投放产品。 */

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

static int count = 0;
static pthread_mutex_t e_lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;

static pthread_mutex_t f_lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;

void *consumer (void *arg) {
    while (true) {
        /* 必须先锁住条件，然后才能判断while (count == 0) */
        pthread_mutex_lock (&e_lock);
        while (count == 0) {
            /* 不使用 if 判断，防止虚假唤醒 */
            pthread_cond_wait (&not_empty, &e_lock);
        }
        --count;
        printf ("consumer:%lu, count=%d\n", pthread_self (), count);
        pthread_mutex_unlock (&e_lock);
        pthread_cond_signal (&not_full);
        usleep (10000);
    }

    return ((void *)0);
}

void *producer (void *arg) {
    while (true) {
        pthread_mutex_lock (&f_lock);
        while (count > 0) {
            pthread_cond_wait (&not_full, &f_lock);
        }
        ++count;
        printf ("producer run, count=%d\n", count);
        pthread_mutex_unlock (&f_lock);

        pthread_cond_signal (&not_empty);
        usleep (10000);
    }

    return ((void *)0);
}

int main (int argc, char *argv[]) {
    const int p_count = 2;
    pthread_t p_tids[p_count];
    for (int i = 0; i < p_count; ++i) {
        if (pthread_create (&p_tids[i], NULL, producer, NULL)) {
            printf ("create thread error");
            return 1;
        }
        pthread_detach (p_tids[i]);
    }

    const int c_count = 3;
    pthread_t c_tids[c_count];
    for (int i = 0; i < c_count; ++i) {
        if (pthread_create (&c_tids[i], NULL, consumer, NULL)) {
            printf ("create thread error");
            return -1;
        }
        pthread_detach (c_tids[i]);
    }

    sleep (1);

    printf ("final count=%d\n", count);

    return 0;
}
