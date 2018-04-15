// -*- coding:utf-8 -*-
// author:phenix3443
// desc:模拟线程的竞争情形
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <vector>
struct Foo
{
        int count;
        Foo():count(0) {}
};

void* work(void *arg) {
        Foo *tmp = (Foo*)arg;
        for (int i=0; i < 5; ++i) {
                ++(tmp->count);
                usleep(10000);
        }

        return ((void*)0);
}

int main(int argc, char *argv[])
{
        Foo f;

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

        std::cout << f.count << std::endl;

        return 0;

}
