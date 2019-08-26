/* -*- coding:utf-8 -*- */
/* libevent监听socket */

#include <event2/event.h>
#include <event2/listener.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <assert.h>
#include <event2/util.h>

/* 打印客户端端口，然后返回 */
void accept_cb (evutil_socket_t fd, short events, void *arg) {
    printf("%s\n", (char *)arg);

    struct sockaddr_in addr;
    socklen_t socklen = sizeof(addr);
    int connfd = accept(fd, (struct sockaddr*)&addr, &socklen);
    u_int16_t port = ntohs (addr.sin_port);
    printf ("client port:%d\n", port);
    close (connfd);
}


int main (int argc, char *argv[]) {
    struct event_base *base = event_base_new ();
    if (!base) {
        printf ("new event base error\n");
        return -1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons (9876);
    addr.sin_addr.s_addr = htonl (0); /* listen 0.0.0.0 */

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);

    /* 设置socket可以重用，方便测试 */
    int reuse = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    int ret = bind(listenfd, (struct sockaddr*)&addr, sizeof(addr));
    assert(ret == 0);

    int backlog = 2;            /* 小于5不生效 */
    ret = listen(listenfd, backlog);
    assert(ret == 0);

    struct event *ev = event_new(base, listenfd, EV_READ | EV_PERSIST, accept_cb, "new connection");
    event_add(ev, NULL);

    event_base_dispatch(base);

    event_free(ev);
    event_base_free (base);
    close(listenfd);
    return 0;
}
