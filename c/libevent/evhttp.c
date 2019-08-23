/* -*- coding:utf-8 -*- */
/* libevent实现的简单的http服务器， */
/* 返回解析以后用户发送的请求内容 */

#include <stdio.h>
#include <event2/event.h>
#include <event2/http.h>
#include <sys/socket.h>

void dump_cb (struct evhttp_request *req, void *data) {
    struct evbuffer *buff = evbuffer_new();
}

void hello_cb (struct evhttp_request *req, void *data) {

}

int main(int argc, char *argv[])
{
    struct event_base *base = event_base_new();
    if (NULL==base) {
        printf("new event base error\n");
        return -1;
    }
    struct evhttp *httpd = evhttp_new(base);
    if (NULL == httpd) {
        printf("new http error\n");
        return -1;
    }

    /* The /dump URI will dump all requests to stdout and say 200 ok. */
    evhttp_set_cb(httpd, "/dump", dump_cb, NULL);

    /* We want to accept arbitrary requests, so we need to set a "generic" */
    /* cb.  We can also add callbacks for specific paths. */
	evhttp_set_gencb(httpd, hello_cb, NULL);

    struct evhttp_bound_socket *sock = evhttp_bind_socket_with_handle(httpd, "127.0.0.1", 9001);
    if (!sock) {
        printf("bind error \n");
        return -1;
    }

    event_base_dispatch(base);

    evhttp_free(httpd);
    event_base_free(base);
    return 0;
}
