/* -*- coding:utf-8; -*- */
/* socket api相关函数 */

#include <assert.h>
#include <stdio.h>

#include <arpa/inet.h> /* inet_pton */
#include <netinet/in.h> /* sockaddr_in */
#include <sys/socket.h>

#include <unistd.h> /* close */

int main (int argc, char *argv[]) {
    char *ip = "127.0.0.1";
    u_int16_t port = 9999;

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons (port); /* 为什么要进行转换？ */
    int ret = inet_pton (AF_INET, ip, (void *)&addr.sin_addr.s_addr);
    assert (ret == 1); /* 返回值 1/0 */

    int listenfd = socket (AF_INET, SOCK_STREAM, 0);
    assert (listenfd > 0); /* 返回值 0//-1 */

    ret = bind (listenfd, (struct sockaddr *)&addr, sizeof (addr));
    assert (ret == 0); /* 返回值 0/-1 */

    u_int32_t backlog = 10;
    ret = listen (listenfd, backlog);
    assert (ret == 0); /* 返回值 0/-1 */

    int connfd = accept (listenfd, NULL, NULL);
    assert (connfd > 0);

    /* get client addr by accept */
    struct sockaddr_in remote_addr;
    socklen_t remote_addr_len = sizeof (remote_addr);
    ret =
        getpeername (connfd, (struct sockaddr *)&remote_addr, &remote_addr_len);
    assert (ret == 0);

    char client_ip[INET_ADDRSTRLEN];
    /* bzero(client_ip, sizeof(client_ip)); */
    inet_ntop (AF_INET, (void *)&remote_addr.sin_addr, client_ip,
               INET_ADDRSTRLEN);
    printf (
        "client ip: %s, client_port: %d\n", client_ip,
        ntohs (remote_addr
                   .sin_port)); /* client ip: 127.0.0.1, client_port: 45204 */

    struct sockaddr_in server_addr;
    socklen_t server_addr_len = sizeof (server_addr);
    ret =
        getsockname (connfd, (struct sockaddr *)&server_addr, &server_addr_len);
    assert (ret == 0);
    char server_ip[INET_ADDRSTRLEN];
    inet_ntop (AF_INET, (void *)&server_addr.sin_addr, server_ip,
               INET_ADDRSTRLEN);
    printf (
        "server ip: %s, sever_port:%d\n", server_ip,
        ntohs (
            server_addr.sin_port)); /* server ip: 127.0.0.1, sever_port:9999 */

    close (connfd);
    close (listenfd);

    return 0;
}
