/* -*- coding:utf-8;-*- */
/* sigactionl函数测试 */

#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>

const u_int32_t max_events = 10;
static int pipfd[2];

int setnoblock (int fd) {
    int o_opt = fcntl (fd, F_GETFL);
    int new_opt = o_opt | O_NONBLOCK;
    fcntl (fd, F_SETFL, new_opt);
    return o_opt;
}

void addfd (int epfd, int fd) {
    struct epoll_event e;
    e.data.fd = fd;
    e.events = EPOLLIN | EPOLLET;
    epoll_ctl (epfd, EPOLL_CTL_ADD, fd, &e);
    setnoblock (fd);
}

void sig_handler (int sig) {
    /* 保留原来的errno，在函数最后恢复，保证函数的可重入性 */
    int save_errno = errno;
    int msg = sig;
    send (pipfd[1], (char *)&msg, 1, 0); /* 将信号值写入管道，通知主循环 */
    errno = save_errno;
}

void add_sig (int sig) {
    struct sigaction sa;
    memset (&sa, '\0', sizeof (sa));
    sa.sa_handler = sig_handler;
    sa.sa_flags |= SA_RESTART;
    sigfillset(&sa.sa_mask);    /* 有什么用？ */
    int ret = sigaction (sig, &sa, NULL);
    assert (ret != -1);
}

int main (int argc, char *argv[]) {
    printf ("pid:%d\n", getpid ());
    char *ip = "127.0.0.1";
    u_int16_t port = 9999;

    int listenfd = socket (AF_INET, SOCK_STREAM, 0);
    assert (listenfd > 0);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons (port);
    int ret = inet_pton (AF_INET, ip, (void *)&addr.sin_addr.s_addr);
    assert (ret > 0);

    ret = bind (listenfd, (struct sockaddr *)&addr, sizeof (addr));
    assert (ret == 0);

    ret = listen (listenfd, 5);
    assert (ret == 0);

    int epfd = epoll_create (max_events);
    assert (epfd > 0);

    addfd (epfd, listenfd);

    /* 使用socketpair创建管道，注册pifd[0]上的读事件 */
    ret = socketpair (AF_UNIX, SOCK_STREAM, 0, pipfd);
    assert (ret == 0);
    addfd (epfd, pipfd[0]);

    add_sig (SIGHUP);
    add_sig (SIGCHLD);
    add_sig (SIGTERM);
    add_sig (SIGINT);

    struct epoll_event events[max_events];

    bool stop = false;
    while (!stop) {
        ret = epoll_wait (epfd, events, max_events, 5000);
        switch (ret) {
            case -1:
                if (errno != EINTR) {
                    printf ("epoll failed \n");
                    break;
                }

            case 0:
                printf ("no active conn\n");

            default:
                for (int i = 0; i < ret; ++i) {
                    int fd = events[i].data.fd;
                    if (fd == listenfd) {
                        int connfd = accept (listenfd, NULL, NULL);
                        assert (connfd > 0);
                        addfd (epfd, connfd);
                    } else if (fd== pipfd[0] && (events[i].events & EPOLLIN))  {
                        char signals[1024];
                        ret = recv (pipfd[0], signals, sizeof (signals), 0);
                        if (ret == -1) {
                            printf ("redv failed\n");
                        } else if (ret == 0) {
                            printf ("redv nothing\n");
                        } else {
                            /* 可能接收到多个信号 */
                            for (int i = 0; i < ret; ++i) {
                                switch (signals[i]) {
                                    case SIGCHLD:
                                        printf ("get sigcld\n");
                                    case SIGHUP:
                                        printf ("get sighup\n");
                                        continue;
                                    case SIGTERM:
                                        printf ("get sigterm\n");
                                    case SIGINT:
                                        printf ("get sigint\n");
                                        stop = true;
                                }
                            }
                        }
                    } else if (events[i].events & EPOLLIN){
                        printf ("get something from conn fd\n");
                        close (fd);
                    }
                }
        }
    }

    close (pipfd[0]);
    close (pipfd[1]);
    close (listenfd);

    return 0;
}
