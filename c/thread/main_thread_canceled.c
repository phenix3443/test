/* -*- coding:utf-8 -*- */
/* desc:主进程死亡对子进程的影响 */
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>


void *cancel_main_thread (void *arg) {
    pthread_t main_tid = *(pthread_t*)arg;
    pthread_cancel (main_tid);
    for (int i=0; i < 5; ++i) {
        printf("child thread alive\n");
        sleep (2);
    }

    return NULL;
}

int main (int argc, char *argv[]) {
    pthread_t tid;
    pthread_t main_tid = pthread_self ();

    if (pthread_create (&tid, NULL, cancel_main_thread,
                        (void *)&main_tid)) {
        printf("thread create error\n");
        return -1;
    }

    pthread_detach (tid);
    for (int i=0; i < 5; ++i) {
        printf("main thread alive\n");
        sleep(1);
    }

    printf("main exit\n");

    return 0;
}
