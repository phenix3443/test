// thread cleanup

#include <iostream>
#include <pthread.h>

void cleanup(void *arg) {
        std::cout << "cleanup：" << (char *)arg << std::endl;
}

void* thread_fn1(void *arg) {
        std::cout << "thread 1 start" << std::endl;

        pthread_cleanup_push(cleanup, const_cast<char*>("thread 1 first handle"));

        pthread_cleanup_push(cleanup, const_cast<char*>("thread 1 second handle"));
        std::cout << "thread 1 push complete" << std::endl;
        if (arg)
                return ((void*)1);
        pthread_cleanup_pop(0);
        pthread_cleanup_pop(1);
        return  ((void*)1);
}

void* thread_fn2(void *arg) {
        std::cout << "thread 2 start" << std::endl;
        pthread_cleanup_push(cleanup, const_cast<char*>("thread 2 first handle"));
        pthread_cleanup_push(cleanup, const_cast<char*>("thread 2 second handle"));
        std::cout << "thread 2 push complete" << std::endl;
        if (arg)
                pthread_exit((void*)2);
        pthread_cleanup_pop(0);
        pthread_cleanup_pop(0);
        return ((void*)2);
}

int main(int argc, char *argv[])
{
        pthread_t tid1, tid2;
        int arg = 1;
        if(pthread_create(&tid1, NULL, thread_fn1, (void*)&arg)) {
                std::cout << "create thread 1 error" << std::endl;
                return 1;
        }
        pthread_join(tid1, NULL);

        if(pthread_create(&tid2, NULL, thread_fn2, (void*)&arg)) {
                std::cout << "create thread 2 error" << std::endl;
                return 2;
        }
        pthread_join(tid2, NULL);

        return 0;
}
