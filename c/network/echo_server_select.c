/* coding:utf-i */
/* 使用select提供简单的回显服务 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>

#include <unistd.h>
#include <fcntl.h>

int setnonblock(int fd) {
    int old_opt = fcntl(fd, F_GETFD);
    int new_opt = old_opt | O_NONBLOCK;
    fcntl(fd, F_SETFD, new_opt);
    return old_opt;
}

void handle_conn(int connfd) {
    /* 获取客户端IP地址 */
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int ret = getpeername(connfd, (struct sockaddr*)&client_addr, &client_addr_len);
    assert(ret == 0);

    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, (void *)&client_addr.sin_addr.s_addr, client_ip, INET_ADDRSTRLEN);
    u_int16_t client_port = ntohs(client_addr.sin_port);

    /* 读取数据 */
    const u_int32_t buff_size = 4096;
    char r_buff[buff_size];
    memset(r_buff, '\0', buff_size);

    ssize_t recv_n = recv(connfd, (void *)r_buff, buff_size, 0);
    if(recv_n > 0) {
        printf("%s:%d say: %s", client_ip, client_port, r_buff);
        ret = send(connfd, r_buff, buff_size, 0);
        assert(ret > 0);
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

    const int max_events = backlog;
    int event_fds[max_events];       /* 用于保存监听事件的套接字 */
    for(int i=0; i<max_events; ++i) {
        event_fds[i] = -1;
    }
    event_fds[0] = listenfd;

    bool server_stop = false;
    while(!server_stop) {
        /* 只监听读取事件 */
        fd_set r_fds;
        FD_ZERO(&r_fds);

        /* 重新设置监听套接字 */
        int maxfd = listenfd;

        for (int i=0; i < max_events; ++i) {
            int connfd = event_fds[i];
            if(connfd != -1) {
                FD_SET(connfd, &r_fds);
                maxfd = (connfd>maxfd)?connfd:maxfd;
            }
        }

        struct timeval tv = {10,0};

        ret = select(maxfd +1, &r_fds, NULL, NULL, &tv);
        switch(ret) {
        case 0:
            printf("no active sock\n");
            break;
        case -1:
            printf("seelct failed\n");
            break;
        default:
            /* 轮询检查已连接套接字是否有事件 */
            for (int i=0; i<max_events; ++i) {
                int fd = event_fds[i];
                if(FD_ISSET(fd, &r_fds)) {
                    if(fd == listenfd) {
                        /* 处理监听套接字 */
                        int connfd = accept(listenfd, NULL, NULL);
                        assert(connfd > 0);
                        /* 添加到集合 */
                        for(int i=0; i < max_events; ++i) {
                            if(event_fds[i] == -1) {
                                event_fds[i] = connfd;
                                break;
                            }
                        }
                        setnonblock(connfd);
                    }
                    else {
                        /* 处理连接套接字 */
                        handle_conn(fd);
                        close(fd);
                        event_fds[i] = -1;
                    }
                }
            }
        }
    }

    close(listenfd);
    return 0;
}
