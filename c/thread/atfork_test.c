// -*- coding:utf-8 -*-
// author:phenix3443
// desc: atfork使用示例

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

void prepare(void) {
    printf("preparing locking....\n");
    if(pthread_mutex_lock(&lock1) || pthread_mutex_lock(&lock2)) {
        printf("prepare error\n");
    }
}

void parent(void) {
    printf("parent unlocking .....\n");
    if(pthread_mutex_unlock(&lock1) || pthread_mutex_unlock(&lock2)) {
        printf("parent error\n");
    }
}

void child(void) {
    printf("child unlocking...\n");
    if(pthread_mutex_unlock(&lock1) || pthread_mutex_unlock(&lock2)) {
        printf("child error\n");
    }
}

void * ThreadFunc(void *arg) {
    printf("thread running\n");
    pause();
    return NULL;
}

int main(int argc, char *argv[])
{
    if(pthread_atfork(prepare, parent, child)) {
        printf("pthread_atfork error\n");
        return 1;
    }
    pthread_t tid;

    if(pthread_create(&tid, NULL, ThreadFunc, NULL)) {
        printf("pthread_create error\n");
        return 2;
    }
    sleep(2);                   // 让子线程先执行
    printf("parent about to forking...\n");

    pid_t pid = fork();
    if (pid == 0) {
        printf("child process return\n");
    }
    else if(pid > 0) {
        waitpid(pid, NULL, 0);
        printf("parent process return\n");
    }
    else {
        printf("fork error\n");
        return 1;
    }

    return 0;
}
