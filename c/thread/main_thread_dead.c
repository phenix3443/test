// -*- coding:utf-8 -*-
// author:phenix3443
// desc:主进程死亡对子进程的影响
#include <pthread.h>
#include <unistd.h>
#include <iostream>

void *cancel_main_thread (void *arg) {
    pthread_t main_tid = *static_cast<pthread_t *> (arg);
    pthread_cancel (main_tid);
    while (true) {
        std::cout << "child thread alive" << std::endl;
        sleep (1);
    }
    return NULL;
}

int main (int argc, char *argv[]) {
    pthread_t tid;
    pthread_t main_tid = pthread_self ();

    if (pthread_create (&tid, NULL, cancel_main_thread,
                        static_cast<void *> (&main_tid))) {
        std::cout << "thread create error" << std::endl;
        return -1;
    }
    pthread_detach (tid);
    while (1) {
        std::cout << "main thread alive" << std::endl;
    }

    std::cout << "main exit" << std::endl;
    return 0;
}
