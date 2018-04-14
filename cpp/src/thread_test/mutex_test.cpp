// -*- coding:utf-8 -*-
// author:phenix3443
// desc:互斥量测试
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <vector>

struct Foo
{
        int count;
        pthread_mutex_t lock;
};

void* work(void *arg) {
        Foo *tmp = (Foo*)arg;

        for(int i=0; i<5; ++i) {
                pthread_mutex_lock(&(tmp->lock));
                ++(tmp->count);
                usleep(1000);
                pthread_mutex_unlock(&(tmp->lock));
        }
        return ((void*)0);
}

int main(int argc, char *argv[])
{
        Foo f;
        f.count = 0;
        if(pthread_mutex_init(&(f.lock), NULL)) {
                std::cout << "mutex init error" << std::endl;
                return 1;
        }

        std::vector<pthread_t> tids(50);
        for (auto &tid : tids) {
                if(pthread_create(&tid, NULL, work, (void*)&f)) {
                        std::cout << "thread create error " << std::endl;
                        return 2;
                }
        }

        for (auto &tid : tids) {
                pthread_join(tid, NULL);
        }
        pthread_mutex_destroy(&f.lock);
        std::cout << f.count << std::endl;
        return 0;

}
