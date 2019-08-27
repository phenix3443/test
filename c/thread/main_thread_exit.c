/* -*- coding:utf-8 -*-  */
/* 线程创建练习 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* work (void *arg) {
    printf ("tid:%lu, %s\n", pthread_self(), (char *)arg);
    pthread_exit (NULL);        /* pthread_exit返回值不应该分配在函数栈上 */
}

int main (int argc, char *argv[]) {
    pthread_t tid;
    int ret = pthread_create (&tid, NULL, work, "new thread");
    if (ret) {
        printf ("thread create error\n");
        return -1;
    }

    printf("main thread done\n");
    pthread_exit(NULL);         /* 退出主线程，不会导致线程退出 */

    return 0;
}
