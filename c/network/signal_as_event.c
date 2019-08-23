/* -*-coding:utf-8 -*- */
/* 信号抽象为事件 */

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
#include <stdbool.h>

static int pipefd[2];

void sig_handler (int sig) {
    int save_errno = errno;
    int msg = sig;
    send (pipefd[1], (char *)&msg, 1, 0);
    errno = save_errno;
}

void add_sig (int sig) {
    struct sigaction sa;
    memset(&sa, '\0', sizeof(sa));
    sa.sa_flags |= SA_RESTART;
    sa.sa_handler = sig_handler;
    sigfillset(&sa.sa_mask);
    int ret = sigaction(sig, &sa, NULL);
    assert(ret != 1);
}

int main (int argc, char *argv[]) {
    printf("pid: %d\n", getpid());
    fflush(stdout);
    add_sig (SIGHUP);
    add_sig (SIGCHLD);
    add_sig (SIGUSR1);
    add_sig (SIGINT);

    int ret = socketpair(AF_UNIX, SOCK_STREAM, 0, pipefd);
    assert(ret == 0);

    struct epoll_event e;
    e.data.fd = pipefd[0];
    e.events = EPOLLIN;

    int epfd = epoll_create (10);
    epoll_ctl(epfd, EPOLL_CTL_ADD, e.data.fd, &e);

    int max_events = 10;
    struct epoll_event events[max_events];

    bool stop = false;
    while (!stop) {
        ret = epoll_wait(epfd, events, max_events, 5000);
        for (int i = 0; i < max_events; ++i) {
            int fd = events[i].data.fd;
            if (fd == pipefd[0] && (events[i].events & EPOLLIN)) {
                char signals[1024];
                ret = recv(fd, signals, sizeof(signals), 0);
                for (int i=0; i<ret; ++i) {
                    switch (signals[i]) {
                    case SIGCHLD:
                        printf ("get sigcld\n");
                        break;
                    case SIGHUP:
                        printf ("get sighup\n");
                        break;
                    case SIGUSR1:
                        printf ("get sigusr1\n");
                        break;
                    case SIGINT:
                        printf ("get sigint\n");
                        stop = true;
                        break;
                    default:
                        printf("undefined signals\n");
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
