/* -*- coding:utf-8 -*- */
/* libevent监听socket */

#include <event2/event.h>
#include <event2/listener.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

void accept_cb (struct evconnlistener *listener, evutil_socket_t sock,
                struct sockaddr *addr, int len, void *ptr) {
    u_int16_t port = ntohs (((struct sockaddr_in *)addr)->sin_port);
    printf ("client port:%d\n", port);
    close (sock);
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

    unsigned flag = LEV_OPT_LEAVE_SOCKETS_BLOCKING| LEV_OPT_CLOSE_ON_FREE | LEV_OPT_REUSEABLE;
    struct evconnlistener *listener =
        evconnlistener_new_bind (base, accept_cb, NULL, flag, 10,
                                 (struct sockaddr *)&addr, sizeof (addr));
    if (!listener) {
        perror ("启动监听端口错误");
        return -1;
    }

    event_base_dispatch(base);

    evconnlistener_free (listener);
    event_base_free (base);

    return 0;
}
