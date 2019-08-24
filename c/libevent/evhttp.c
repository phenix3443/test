/* -*- coding:utf-8 -*- */
/* libevent实现的简单的http服务器， */
/* 返回解析以后用户发送的请求内容 */

#include <assert.h>
#include <event2/buffer.h>
#include <event2/event.h>
#include <event2/http.h>
#include <event2/keyvalq_struct.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>

const char *get_cmd_type (enum evhttp_cmd_type n) {
    const char *cmdtype;
    switch (n) {
        case EVHTTP_REQ_GET:
            cmdtype = "GET";
            break;
        case EVHTTP_REQ_POST:
            cmdtype = "POST";
            break;
        case EVHTTP_REQ_HEAD:
            cmdtype = "HEAD";
            break;
        case EVHTTP_REQ_PUT:
            cmdtype = "PUT";
            break;
        case EVHTTP_REQ_DELETE:
            cmdtype = "DELETE";
            break;
        case EVHTTP_REQ_OPTIONS:
            cmdtype = "OPTIONS";
            break;
        case EVHTTP_REQ_TRACE:
            cmdtype = "TRACE";
            break;
        case EVHTTP_REQ_CONNECT:
            cmdtype = "CONNECT";
            break;
        case EVHTTP_REQ_PATCH:
            cmdtype = "PATCH";
            break;
        default:
            cmdtype = "unknown";
            break;
    }
    return cmdtype;
}

/* curl -iv -X POST -d 'hello,world' 'http://127.0.0.1:9876/dump?a=1&b=2' */
void dump_cb (struct evhttp_request *req, void *data) {
    const char *cmdtype = get_cmd_type (evhttp_request_get_command (req));

    const char *uri = evhttp_request_get_uri (req);
    printf ("Received a %s request for %s\n", cmdtype, uri);

    printf ("query args:\n");
    const struct evhttp_uri *ev_uri = evhttp_request_get_evhttp_uri (req);
    const char *query = evhttp_uri_get_query (ev_uri);
    struct evkeyvalq query_headers;
    int ret = evhttp_parse_query_str (query, &query_headers);
    assert (ret == 0);
    for (struct evkeyval *header = query_headers.tqh_first; header;
         header = header->next.tqe_next) {
        printf ("%s:%s\n", header->key, header->value);
    }

    printf ("input headers:\n");
    struct evkeyvalq *input_headers = evhttp_request_get_input_headers (req);
    for (struct evkeyval *header = input_headers->tqh_first; header;
         header = header->next.tqe_next) {
        printf ("%s:%s\n", header->key, header->value);
    }

    struct evbuffer *input_buff = evhttp_request_get_input_buffer (req);
    int r_body_len = evbuffer_get_length (input_buff);
    char r_body[r_body_len + 1];
    memset (r_body, '\0', sizeof (r_body));
    ret = evbuffer_copyout (input_buff, r_body, r_body_len);
    printf ("request body:%s\n", r_body);

    printf ("output headers:\n");
    struct evkeyvalq *output_headers = evhttp_request_get_output_headers (req);
    for (struct evkeyval *header = output_headers->tqh_first; header;
         header = header->next.tqe_next) {
        printf ("%s:%s\n", header->key, header->value);
    }

    char *server_msg = "server get:";
    struct evbuffer *output_buff = evhttp_request_get_output_buffer (req);
    evbuffer_add (output_buff, server_msg, strlen (server_msg));
    evbuffer_add (output_buff, r_body, r_body_len);
    evbuffer_add (output_buff, "\n", 1);
    evhttp_send_reply (req, HTTP_OK, "ok", output_buff);
}

/* curl -i http://127.0.0.1:9876 */
void hello_cb (struct evhttp_request *req, void *data) {
    char *msg = "hello,world!\n";
    struct evbuffer *buf = evbuffer_new ();
    int ret = evbuffer_add (buf, msg, strlen (msg));
    assert (ret == 0);
    evhttp_send_reply (req, HTTP_OK, "OK", buf);

    evbuffer_free (buf);
}

int main (int argc, char *argv[]) {
    struct event_base *base = event_base_new ();
    if (NULL == base) {
        printf ("new event base error\n");
        return -1;
    }
    struct evhttp *httpd = evhttp_new (base);
    if (NULL == httpd) {
        printf ("new http error\n");
        return -1;
    }

    /* The /dump URI will dump all requests to stdout and say 200 ok. */
    evhttp_set_cb (httpd, "/dump", dump_cb, NULL);

    /* We want to accept arbitrary requests, so we need to set a "generic" */
    /* cb.  We can also add callbacks for specific paths. */
    evhttp_set_gencb (httpd, hello_cb, NULL);

    /* bind listen socket */
    struct evhttp_bound_socket *sock =
        evhttp_bind_socket_with_handle (httpd, "127.0.0.1", 9876);
    if (!sock) {
        printf ("bind error \n");
        return -1;
    }

    event_base_dispatch (base);

    evhttp_free (httpd);
    event_base_free (base);
    return 0;
}
