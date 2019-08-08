/* coding:utf-i */
/* 使用阻塞IO，提供简单的回显服务 */
/* 这个程序只能只能对连接进行串行处理，在当前连接处理完之前，不能处理后续连接 */
/* 当连接数量超过accept中的backlog 参数时，不能接受新的连接，可以抓包观察此时客户端连接状态*/
/* 更好的方式是使用IO复用：select、poll、epoll */
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#include <sys/socket.h>
#include <arpa/inet.h>

#include <unistd.h>

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

    int backlog = 2;            /* 小于5不生效 */
    ret = listen(listenfd, backlog);
    assert(ret == 0);

    bool server_stop = false;

    while(!server_stop) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int connfd = accept(listenfd, (struct sockaddr*)&client_addr, &client_addr_len);
        assert(connfd > 0);

        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, (void*)&client_addr.sin_addr.s_addr, client_ip, INET_ADDRSTRLEN);
        u_int16_t client_port = ntohs(client_addr.sin_port);

        const u_int32_t buff_size = 4096;
        char r_buff[buff_size];
        memset(r_buff, '\0', buff_size);

        ssize_t recv_n = recv(connfd, (void*)r_buff, buff_size, 0);
        if(recv_n > 0) {
            printf("%s:%d say: %s", client_ip, client_port, r_buff);
            ret = send(connfd, r_buff, buff_size, 0);
            assert(ret > 0);
        }

        close(connfd);
    }

    close(listenfd);
    return 0;
}
