/* coding:utf-8 */
/* socket api相关函数 */

#include <stdio.h>
#include <assert.h>


#include <sys/socket.h>
#include <netinet/in.h>         /* sockaddr_in */
#include <arpa/inet.h>         /* inet_pton */

#include <unistd.h>             /* close */
#include <string.h>

int main(int argc, char *argv[])
{

    char *ip = "127.0.0.1";
    u_int16_t port = 9999;

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port); /* 为什么要进行转换？ */
    int ret = inet_pton(AF_INET, ip, (void *)&addr.sin_addr.s_addr);
    assert(ret == 1); /* 返回值 1/0 */

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    assert(listenfd > 0);       /* 返回值 0//-1 */

    /* 设置socket可以重用，方便测试 */
    int reuse = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    ret = bind(listenfd, (struct sockaddr *)&addr, sizeof(addr));
    assert(ret == 0);           /* 返回值 0/-1 */

    u_int32_t backlog = 10;
    ret = listen(listenfd, backlog);
    assert(ret == 0);           /* 返回值 0/-1 */

    /* get client addr by accept */
    struct sockaddr_in remote_addr;
    socklen_t remote_addr_len = sizeof(remote_addr); /* 注意这里要初始化remote_add_len */
    int connfd = accept(listenfd, (struct sockaddr*)&remote_addr, &remote_addr_len);
    assert(connfd > 0);

    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, (void *)&remote_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
    u_int16_t client_port = ntohs(remote_addr.sin_port);

    const u_int32_t buff_size = 4096;
    char r_buff[buff_size];
    memset(r_buff, '\0', buff_size);

    ssize_t recv_n = recv(connfd, (void *)r_buff, buff_size, 0);
    if(recv_n > 0) {
        printf("%s:%d say: %s", client_ip, client_port, r_buff);
        ret = send(connfd, r_buff, buff_size, 0);
        assert(ret > 0);
    }

    close(connfd);
    close(listenfd);

    return 0;
}
