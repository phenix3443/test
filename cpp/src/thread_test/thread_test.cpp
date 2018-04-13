// -*- coding:utf-8 -*-
// 线程练习


#include <iostream>
#include <unistd.h>
#include <pthread.h>

void print_tid(const char *str) {
        pid_t pid = getpid();
        pthread_t tid = pthread_self();
        std::cout << str << " pid: " << pid << " tid:" << tid << std::endl;
}

void* work(void *arg) {
        print_tid("new thread:");
        // return ((void *)0);
        pthread_exit((void*)2);
}

int main(int argc, char *argv[])
{
        pthread_t tid;
        int ret = pthread_create(&tid, NULL, work, NULL);
        if (ret) {
                std::cout << "thread create error" << std::endl;
        }
        void *tret;
        pthread_join(tid,&tret);
        std::cout << "new thread: tid: " << tid << " return value:" << (long *)tret << std::endl;
        print_tid("Main Thread:");
        sleep(1);
        return 0;
}
