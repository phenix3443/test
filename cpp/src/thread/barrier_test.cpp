// -*- coding:utf-8 -*-
// author:phenix3443
// desc: 屏障（barrier）使用示例


#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <vector>
#include <cstdlib>

void *first_work(void *arg) {
        pthread_barrier_t *b = static_cast<pthread_barrier_t *>(arg);
        unsigned int i = rand() % 1000 + 100;
        std::cout << pthread_self() << " sleep " << i << "microseconds" << std::endl;
        usleep(i);
        int res = pthread_barrier_wait(b);
        if (res == PTHREAD_BARRIER_SERIAL_THREAD) {
                std::cout << pthread_self() << " all thread done first work!" << std::endl;
        }
        return ((void*)0);
}

int main(int argc, char *argv[])
{
        const int thread_num = 10;
        pthread_barrier_t b;
        pthread_barrier_init(&b, NULL, thread_num);
        std::vector<pthread_t> tids(thread_num);
        for(auto &tid : tids) {
                if(pthread_create(&tid, NULL, first_work, (void*)&b)) {
                        std::cout << "create thread error" << std::endl;
                        return 1;
                }
        }

        for(auto &tid : tids) {
                pthread_join(tid, NULL);
        }
        pthread_barrier_destroy(&b);
        return 0;
}
