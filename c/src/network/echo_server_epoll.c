/* coding:utf-i */
/* 使用epoll提供简单的回显服务 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

#include <unistd.h>
#include <fcntl.h>

int setnonblock(int fd) {
    int old_opt = fcntl(fd, F_GETFL);
    int new_opt = old_opt | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_opt);
    return old_opt;
}

void addfd(int epoll_fd, int fd, bool enable_et) {
    struct epoll_event e;
    e.data.fd = fd;
    e.events = EPOLLIN;
    if(enable_et) {
        e.events |= EPOLLET;
    }
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &e);
    setnonblock(fd);
}

void get_client_addr(int connfd, char *ip, u_int16_t *port) {
    /* 获取客户端IP地址 */
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int ret = getpeername(connfd, (struct sockaddr*)&client_addr, &client_addr_len);
    assert(ret == 0);

    inet_ntop(AF_INET, (void *)&client_addr.sin_addr.s_addr, ip, INET_ADDRSTRLEN);
    *port = ntohs(client_addr.sin_port);
}

void lt(int epfd, struct epoll_event *events, int num, int listenfd) {
    for(int i=0; i<num; ++i) {
        int fd = events[i].data.fd;
        if(fd == listenfd) {
            printf("hello");
            int connfd = accept(listenfd, NULL, NULL);
            assert(connfd > 0);
            addfd(epfd, connfd, false);
        }
        else if(events[i].events & EPOLLIN){
            printf("world");
            char client_ip[INET_ADDRSTRLEN];
            u_int16_t client_port;
            get_client_addr(fd, client_ip, &client_port);

            /* 读取数据 */
            const u_int32_t buff_size = 4096;
            char r_buff[buff_size];
            memset(r_buff, '\0', buff_size);

            ssize_t recv_n = recv(fd, (void *)r_buff, buff_size, 0);
            if(recv_n > 0) {
                printf("%s:%d say: %s", client_ip, client_port, r_buff);
                int ret = send(fd, r_buff, buff_size, 0);
                assert(ret > 0);
            }

            close(fd);
        }
        else {
            printf("something else happend\n");
        }
    }
}

void et(int epfd, struct epoll_event *events, int num, int listenfd) {
    for(int i=0; i<num; ++i) {
        int fd = events[i].data.fd;
        if (fd == listenfd) {
            int connfd = accept(listenfd, NULL, NULL);
            assert(connfd > 0);
            addfd(epfd, connfd, true);
        }
        else {
            char client_ip[INET_ADDRSTRLEN];
            u_int16_t client_port;
            get_client_addr(fd, client_ip, &client_port);

            /* 读取数据 */
            const u_int32_t buff_size = 4096;
            char r_buff[buff_size];
            while(true) {
                /* ET 模式下，使用循环一次读取所有数据 */
                memset(r_buff, '\0', buff_size);
                int ret = recv(fd, (void *)r_buff, buff_size-1, 0);
                if(ret < 0) {
                    /* 发生错误 */
                    if(errno == EAGAIN || errno == EWOULDBLOCK) {
                        /* 没有更多的数据 */
                        printf("read later\n");
                    }
                    break;
                }
                else if(ret == 0){
                    /* 对方关闭套接字 */
                    break;
                }
                else{
                    printf("%s:%d say: %s", client_ip, client_port, r_buff);
                    int ret = send(fd, r_buff, buff_size, 0);
                    assert(ret > 0);
                }
            }
            close(fd); /* 注意关闭套接字 */
            epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
        }
    }
}

int main(int argc, char *argv[])
{
    char *ip = "127.0.0.1";
    u_int16_t port = 9999;

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    int ret = inet_pton(AF_INET, ip, (void *)&addr.sin_addr.s_addr);
    assert(ret == 1);

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    assert(listenfd > 0);

    /* 设置socket可以重用，方便测试 */
    int reuse = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    ret = bind(listenfd, (struct sockaddr*)&addr, sizeof(addr));
    assert(ret == 0);

    int backlog = 6;            /* 小于5不生效 */
    ret = listen(listenfd, backlog);
    assert(ret == 0);

    int epfd = epoll_create(backlog);
    addfd(epfd, listenfd, true);

    const int max_events = backlog;
    struct epoll_event events[max_events];

    bool server_stop = false;
    while(!server_stop) {
        /* 只监听读取事件 */
        ret = epoll_wait(epfd, events, max_events, 5000);
        switch(ret) {
        case 0:
            printf("no active sock\n");
            break;
        case -1:
            printf("poll failed\n");
            break;
        default:
            /* lt(epfd, events, ret, listenfd); */
            et(epfd, events, ret, listenfd);
        }
    }

    close(listenfd);
    return 0;
}
