// -*- coding:utf-8 -*-
// author:phenix3443
// desc:读写锁
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <vector>

struct Foo
{
        int count;
        pthread_rwlock_t lock;
        Foo():count(0),lock(PTHREAD_RWLOCK_INITIALIZER) {}
        ~Foo() {
                pthread_rwlock_destroy(&lock);
        }
};

void* write(void *arg) {
        Foo *tmp = (Foo*)arg;
        pthread_rwlock_wrlock(&(tmp->lock));
        ++(tmp->count);
        std::cout << "write thread: " << pthread_self() << " after add cout " << tmp->count << std::endl;
        pthread_rwlock_unlock(&(tmp->lock));

        return ((void*)0);
}

void* read(void *arg) {
        Foo *tmp = (Foo*)arg;
        while(true) {
                pthread_rwlock_rdlock(&(tmp->lock));
                std::cout << "read thread: " << pthread_self() << " count: " << tmp->count << std::endl;
                pthread_rwlock_unlock(&(tmp->lock));
                usleep(100);    // 减少read时候打印数量
        }
        return ((void*)0);
}

int main(int argc, char *argv[])
{
        Foo f;

        std::vector<pthread_t> rtids(3);
        for (auto & tid : rtids) {
                if(pthread_create(&tid, NULL, read, (void*)&f)) {
                        std::cout << "thread create error " << std::endl;
                        return 2;
                }
        }

        std::vector<pthread_t> wtids(10);
        for (auto & tid : wtids) {
                if(pthread_create(&tid, NULL, write, (void*)&f)) {
                        std::cout << "thread create error " << std::endl;
                        return 2;
                }
                pthread_join(tid, NULL);
                usleep(10);     // 让read线程执行
        }

        std::cout << f.count << std::endl;
        return 0;

}
