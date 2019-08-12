#include <pthread.h>
#include <unistd.h>

void *work (void *arg) {
    while (1) {
    }
    return (void *)0;
}

int main (int argc, char *argv[]) {
    const int tnum = 3;
    pthread_t tids[tnum];
    std::cout << "pid: " << getpid () << std::endl;
    for (int i = 0; i < tnum; ++i) {
        if (pthread_create (&tids[i], NULL, work, NULL)) {
            std::cout << "error: create" << std::endl;
            return -1;
        }
    }
    while (1) {
    }
    return 0;
}
