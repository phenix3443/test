/* -*- coding:utf-8 -*-  */
/* 线程练习 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void print_tid () {
    pid_t pid = getpid ();
    pthread_t tid = pthread_self ();
    printf ("pid:%d, tid:%lu\n", pid, tid);
}

void* work (void *arg) {
    printf ("%s\n", (char *)arg);
    print_tid ();
    pthread_exit (NULL);        /* pthread_exit返回值不应该分配在函数栈上 */
}

int main (int argc, char *argv[]) {
    pthread_t tid;
    int ret = pthread_create (&tid, NULL, work, "new thread");
    if (ret) {
        printf ("thread create error\n");
        return -1;
    }
    pthread_join (tid, NULL);

    printf("main thread\n");
    print_tid ();
    return 0;
}
