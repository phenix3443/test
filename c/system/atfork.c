// -*- coding:utf-8 -*-
// author:phenix3443
// desc: atfork使用示例

#include <pthread.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

void prepare (void) {
    printf ("preparing locking....");
    if (pthread_mutex_lock (&lock1) || pthread_mutex_lock (&lock2)) {
        printf ("prepare error");
    }
}

void parent (void) {
    printf ("parent unlocking .....");
    if (pthread_mutex_unlock (&lock1) || pthread_mutex_unlock (&lock2)) {
        printf ("parent error");
    }
}

void child (void) {
    printf ("child unlocking...");
    if (pthread_mutex_unlock (&lock1) || pthread_mutex_unlock (&lock2)) {
        printf ("child error");
    }
}

void *ThreadFunc (void *arg) {
    printf ("thread running");
    pause ();
    return NULL;
}

int main (int argc, char *argv[]) {
    if (pthread_atfork (prepare, parent, child)) {
        printf ("pthread_atfork error");
        return 1;
    }
    pthread_t tid;

    if (pthread_create (&tid, NULL, ThreadFunc, NULL)) {
        printf ("pthread_create error");
        return 2;
    }
    sleep (2);  // 让子线程先执行printf( "parent about to forking..." <<
                // std::endl;
    pid_t pid = fork ();
    if (pid == 0) {
        printf ("child process return");
    } else if (pid > 0) {
        waitpid (pid, NULL, 0);
        printf ("parent process return");
    } else {
        printf ("fork error");
        return 1;
    }

    return 0;
}
