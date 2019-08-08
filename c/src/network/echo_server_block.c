/* coding:utf-i */
/* 使用阻塞IO，提供简单的回显服务 */


#include <stdio.h>
#include <assert.h>
#include <string.h>

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

    ret = bind(listenfd, (struct sockaddr*)&addr, sizeof(addr));
    assert(ret == 0);

    int backlog = 10;
    ret = listen(listenfd, backlog);
    assert(ret == 0);

    int connfd = accept(listenfd, NULL, NULL);
    assert(connfd > 0);

    const u_int32_t buff_size = 4096;
    char r_buff[buff_size];
    memset(r_buff, '\0', buff_size);

    while(recv(connfd, (void*)r_buff, buff_size, 0) > 0) {
        printf("recv: %s", r_buff);
        ret = send(connfd, r_buff, buff_size, 0);
        assert(ret > 0);
    }

    close(connfd);
    close(listenfd);
    return 0;
}
