/* -*- coding:utf-8 -*- */
/* libevent定时器消息 */

#include <event2/event.h>
#include <stdio.h>
#include <time.h>

void timer_handler (int sock, short event, void *arg) {
    printf ("%s\n", (char *)arg);
}

int main (int argc, char *argv[]) {
    struct event_base *base = event_base_new ();
    if (!base) {
        printf ("new event base error\n");
        return -1;
    }

    struct event *ev = event_new (base, -1, EV_PERSIST, timer_handler, "hello,world");
    if (!ev) {
        printf ("new event failed\n");
        return -1;
    }
    struct timeval tv = {3, 0}; /* 3 secondsx */
    event_add (ev, &tv);

    event_base_dispatch (base);

    event_base_free (base);
    event_free (ev);

    return 0;
}
