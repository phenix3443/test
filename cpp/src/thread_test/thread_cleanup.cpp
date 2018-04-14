// -*- coding:utf-8 -*-
// author:phenix3443
// desc:pthread_cleanup_相关函数实验

#include <iostream>
#include <pthread.h>
#include <unistd.h>

void cleanup(void *arg) {
        std::cout << "cleanup：" << (char *)arg << std::endl;
}

void* at_cleanup_pop(void *arg) {
        std::cout << "thread " << pthread_self() << " start" << std::endl;
        pthread_cleanup_push(cleanup, const_cast<char*>("toggle in pop with 1"));
        pthread_cleanup_push(cleanup, const_cast<char*>("toggle in pop with 0"));

        pthread_cleanup_pop(0);
        pthread_cleanup_pop(1);

        return  ((void*)1);
}

void* at_pthread_exit(void *arg) {
        std::cout << "thread " << pthread_self() << " start" << std::endl;
        pthread_cleanup_push(cleanup, const_cast<char*>("toggle in pthread_exit"));
        pthread_exit((void *)2);
        pthread_cleanup_pop(0);
}

void* at_pthread_cancel(void *arg) {
        std::cout << "thread " << pthread_self() << " start" << std::endl;
        pthread_cleanup_push(cleanup, const_cast<char*>("toggle in pthread_cancel"));
        // The cleanup happen asynchronously with respect to the  pthread_can‐cel()  call;
        while(true) {
                std::cout << "child thread alive" << std::endl;
                sleep(1);
        }

        pthread_cleanup_pop(0);
        return ((void*)0);
}

void* at_pthread_return(void *arg) {
        std::cout << "thread " << pthread_self() << " start" << std::endl;
        pthread_cleanup_push(cleanup, const_cast<char*>("toggle in pthread return"));
        return ((void*)0);
        pthread_cleanup_pop(0);
}

int main(int argc, char *argv[])
{
        pthread_t tid1;
        if(pthread_create(&tid1, NULL, at_cleanup_pop, NULL)) {
                std::cout << "create thread 1 error" << std::endl;
                return 1;
        }
        pthread_join(tid1, NULL);


        pthread_t tid2;
        if(pthread_create(&tid2, NULL, at_pthread_exit, NULL)) {
                std::cout << "create thread 2 error" << std::endl;
                return 2;
        }
        pthread_join(tid2, NULL);

        pthread_t tid3;
        if(pthread_create(&tid3, NULL, at_pthread_cancel, NULL)) {
                std::cout << "create thread 3 error" << std::endl;
                return 2;
        }
        sleep(2);
        pthread_cancel(tid3);
        sleep(3);

        pthread_t tid4;
        if(pthread_create(&tid4, NULL, at_pthread_return, NULL)) {
                std::cout << "create thread 2 error" << std::endl;
                return 2;
        }
        pthread_join(tid4, NULL);

        return 0;
}
