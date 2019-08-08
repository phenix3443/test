/* coding:utf-i */
/* 使用poll提供简单的回显服务 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <poll.h>

#include <unistd.h>


void handle_conn(int connfd) {
    /* 获取客户端IP地址 */
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int ret = getpeername(connfd, (struct sockaddr*)&client_addr, &client_addr_len);
    assert(ret == 0);

    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, (void*)&client_addr.sin_addr.s_addr, client_ip, INET_ADDRSTRLEN);
    u_int16_t client_port = ntohs(client_addr.sin_port);

    /* 读取数据 */
    const u_int32_t buff_size = 4096;
    char r_buff[buff_size];
    memset(r_buff, '\0', buff_size);

    ssize_t recv_n = recv(connfd, (void*)r_buff, buff_size, 0);
    if(recv_n > 0) {
        printf("%s:%d say: %s", client_ip, client_port, r_buff);
        ret = send(connfd, r_buff, buff_size, 0);
        assert(ret > 0);
    }
}

int main(int argc, char *argv[])
{
    char* ip = "127.0.0.1";
    u_int16_t port = 9999;

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    int ret = inet_pton(AF_INET, ip, (void*)&addr.sin_addr.s_addr);
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

    struct pollfd pollfds[backlog];       /* 用于保存已经连接的套接字 */
    for(int i=0; i<backlog; ++i) {
        pollfds[i].fd = -1;
    }

    pollfds[0].fd = listenfd;
    pollfds[0].events = POLLIN;

    bool server_stop = false;
    while(!server_stop) {
        /* 只监听读取事件 */
        ret = poll(pollfds, backlog, -1);
        switch(ret) {
        case 0:
            printf("no active sock\n");
            break;
        case -1:
            printf("poll failed\n");
            break;
        default:
            for (int i=0; i<backlog; ++i) {
                if(pollfds[i].revents & POLLIN) {
                    if(pollfds[i].fd == listenfd) {
                        int connfd = accept(listenfd, NULL, NULL);
                        assert(connfd > 0);
                        /* 添加到集合 */
                        for(int i=0; i < backlog; ++i) {
                            if(pollfds[i].fd == -1) {
                                pollfds[i].fd = connfd;
                                pollfds[i].events = POLLIN;
                                break;
                            }
                        }
                    }
                    else {
                        int connfd = pollfds[i].fd;
                        handle_conn(connfd);
                        close(connfd);
                        pollfds[i].fd = -1;
                        pollfds[i].fd = 0;
                    }
                }
            }
        }
    }
    close(listenfd);
    return 0;
}
