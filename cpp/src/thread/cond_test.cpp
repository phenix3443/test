// -*- coding:utf-8 -*-
// author:phenix3443
// desc:使用条件变量模拟生产者和消费这问题
// 1. 生产者和消费这共享缓冲区。
// 2. 不允许消费者到一个空的缓冲区中取产品
// 3. 不允许生产者向一个已经装满产品且尚未被取走的缓冲区中投放产品。

#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <vector>

struct Foo
{
        int count;
        pthread_mutex_t lock;
        pthread_cond_t not_empty;
        pthread_cond_t not_full;

        Foo():count(0),lock(PTHREAD_MUTEX_INITIALIZER),not_empty(PTHREAD_COND_INITIALIZER) ,not_full(PTHREAD_COND_INITIALIZER){}
};


void* consumer(void *arg) {
        Foo *tmp = static_cast<Foo*>(arg);

        while(true){
                pthread_mutex_lock(&tmp->lock); //必须先锁住条件，然后才能判断
                while(tmp->count == 0) {//不使用 if 判断，防止虚假唤醒
                        pthread_cond_wait(&tmp->not_empty, &tmp->lock);
                }
                --tmp->count;
                std::cout << "consumer: " << pthread_self() << " , count="<<tmp->count << std::endl;
                pthread_mutex_unlock(&tmp->lock);
                pthread_cond_signal(&tmp->not_full);
        }

        return ((void*)0);
}

void* producer(void *arg) {
        Foo *tmp = static_cast<Foo*>(arg);
        while(true) {
                pthread_mutex_lock(&tmp->lock);
                while(tmp->count > 0) {
                        pthread_cond_wait(&tmp->not_full, &tmp->lock);
                }
                ++tmp->count;
                std::cout << "producer run, count=" << tmp->count << std::endl;
                pthread_mutex_unlock(&tmp->lock);

                pthread_cond_signal(&tmp->not_empty);
        }

        return ((void*)0);
}

int main(int argc, char *argv[])
{
        Foo f;

        std::vector<pthread_t> c_tids(5);
        for(auto &tid : c_tids) {
                if(pthread_create(&tid, NULL, consumer, static_cast<void*>(&f))) {
                        std::cout << "create thread error" << std::endl;
                        return 1;
                }
        }

        std::vector<pthread_t> p_tids(5);
        for(auto &tid : p_tids) {
                if(pthread_create(&tid, NULL, producer, static_cast<void*>(&f))) {
                        std::cout << "create thread error" << std::endl;
                        return 1;
                }
        }

        usleep(100);
        for(auto &tid : p_tids) {
                pthread_cancel(tid);
        }
        for(auto &tid : c_tids) {
                pthread_cancel(tid);
        }

        std::cout << f.count << std::endl;

        return 0;
}
