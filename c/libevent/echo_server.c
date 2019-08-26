/* -*- coding:utf-8; -*- */
/*libevents实现的单的回显服务器 */

#include <stdlib.h>
#include <event2/event.h>
#include <sys/socket.h>
#include <event2/listener.h>
#include <unistd.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>

void read_cb (struct bufferevent *bev, void *ctx) {
    struct evbuffer *input = bufferevent_get_input(bev);
    struct evbuffer *output = bufferevent_get_output(bev);

    evbuffer_add_buffer(output, input);
}

void event_cb (struct bufferevent *bev, short events, void *ctx) {
    if (events & BEV_EVENT_ERROR) {
        perror("Error from bufferevent");
    }
    if (events & (BEV_EVENT_EOF | BEV_EVENT_ERROR)) {
        bufferevent_free(bev);
    }
}

/* 接受新连接 */
void accept_cb (struct evconnlistener *listener, evutil_socket_t sock,
                struct sockaddr *addr, int len, void *ptr) {
    printf("accetpt args:%s\n", (char *)ptr);
    u_int16_t port = ntohs (((struct sockaddr_in *)addr)->sin_port);
    printf ("client port:%d\n", port);

    struct event_base *base = evconnlistener_get_base(listener);
    struct bufferevent *bev = bufferevent_socket_new(base, sock, BEV_OPT_CLOSE_ON_FREE);
    bufferevent_setcb(bev, read_cb, NULL, event_cb,NULL);
    bufferevent_enable(bev, EV_READ | EV_WRITE);
}

int main(int argc, char *argv[])
{
    struct event_base *base = event_base_new ();
    if (!base) {
        printf ("new event base error\n");
        return -1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons (9876);
    addr.sin_addr.s_addr = htonl (0); /* listen 0.0.0.0 */

    const char *accept_ptr = "accept new connect";
    unsigned flag = LEV_OPT_CLOSE_ON_FREE | LEV_OPT_REUSEABLE;
    struct evconnlistener *listener =
        evconnlistener_new_bind (base, accept_cb, (void *)accept_ptr, flag, -1,
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
