/* -*-coding:utf-8 -*- */
/* 超时抽象为事件 */

#include <stdio.h>
#include <time.h>
#include <sys/epoll.h>
#include <assert.h>
#include <signal.h>
#include <sys/socket.h>
#include <errno.h>
#include <stdbool.h>
#include <unistd.h>

static int pipefd[2];

void sig_handler (int sig) {
    int save_err = errno;
    send(pipefd[1], (char*)&sig, 1, 0);
    errno = save_err;
}

void add_sig (int sig) {
    struct sigaction sa;
    sa.sa_flags |= SA_RESTART;
    sa.sa_handler = sig_handler;
    sigfillset(&sa.sa_mask);
    int ret = sigaction(sig, &sa, NULL);
    assert(ret != 1);
}

int main(int argc, char *argv[])
{
    printf("pid: %d\n", getpid());
    fflush(stdout);

    add_sig(SIGALRM);

    alarm(3);
    alarm(5);

    int ret = socketpair(AF_UNIX, SOCK_STREAM, 0, pipefd);
    assert(ret == 0);

    struct epoll_event e;
    e.data.fd = pipefd[0];
    e.events = EPOLLIN;

    int epfd = epoll_create(10);
    ret = epoll_ctl(epfd, EPOLL_CTL_ADD, e.data.fd, &e);
    assert(ret == 0);

    const int max_events = 10;
    struct epoll_event events[max_events];

    bool stop = false;
    while (!stop) {
        ret = epoll_wait(epfd, events, max_events, 5000);
        for (int i=0; i<ret; ++i) {
            int fd = events[i].data.fd;
            if (fd == pipefd[0] && (events[i].events & EPOLLIN)) {
                char signals[1024];
                ret = recv(fd, signals, sizeof(signals), 0);
                for (int i=0; i<ret; ++i) {
                    switch (signals[i]) {
                    case SIGALRM:
                        printf ("get sigalarm\n");
                        break;
                    case SIGUSR1:
                        printf ("get sigusr1\n");
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }

    close(pipefd[0]);
    close(pipefd[1]);
    return 0;
}
