/* -*- coding:utf-8 -*-  */
/* 主线程退出对子线程的影响 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *work (void *arg) {
    for (int i = 0; i < 5; ++i) {
        printf ("child thread alive\n");
        sleep (2);
    }
}

int main (int argc, char *argv[]) {
    pthread_t tid;
    int ret = pthread_create (&tid, NULL, work, "new thread");
    if (ret) {
        printf ("thread create error\n");
        return -1;
    }

    for (int i = 0; i < 3; ++i) {
        printf ("main thread alive\n");
        sleep (1);
    }
    pthread_exit (NULL); /* 退出主线程，不会导致线程退出 */

    printf("process done");     /* 这句不会打印，因为main_thread 已经死了 */
    return 0;
}
