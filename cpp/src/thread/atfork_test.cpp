// -*- coding:utf-8 -*-
// author:phenix3443
// desc: atfork使用示例

#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <vector>
#include <sys/wait.h>

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

void prepare(void) {
        std::cout << "preparing locking...." << std::endl;
        if(pthread_mutex_lock(&lock1) || pthread_mutex_lock(&lock2)) {
                std::cout << "prepare error" << std::endl;
        }
}

void parent(void) {
        std::cout << "parent unlocking ....." << std::endl;
        if(pthread_mutex_unlock(&lock1) || pthread_mutex_unlock(&lock2)) {
                std::cout << "parent error" << std::endl;
        }
}

void child(void) {
        std::cout << "child unlocking..." << std::endl;
        if(pthread_mutex_unlock(&lock1) || pthread_mutex_unlock(&lock2)) {
                std::cout << "child error" << std::endl;
        }
}

void* ThreadFunc(void *arg) {
        std::cout << "thread running" << std::endl;
        pause();
        return NULL;
}

int main(int argc, char *argv[])
{
        if(pthread_atfork(prepare, parent, child)) {
                std::cout << "pthread_atfork error" << std::endl;
                return 1;
        }
        pthread_t tid;

        if(pthread_create(&tid, NULL, ThreadFunc, NULL)) {
                std::cout << "pthread_create error" << std::endl;
                return 2;
        }
        sleep(2); 					// 让子线程先执行
        std::cout << "parent about to forking..." << std::endl;
        pid_t pid = fork();
        if (pid == 0) {
                std::cout << "child process return" << std::endl;
        }
        else if(pid > 0) {
                waitpid(pid, NULL, 0);
                std::cout << "parent process return" << std::endl;
        }
        else {
                std::cout << "fork error" << std::endl;
                return 1;
        }

        return 0;
}
