/* -*- coding:utf-8 -*- */
/* libevent处理信号消息 */

#include <event2/event.h>
#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

void signal_cb (int sock, short event, void *arg) {
    printf ("%s\n", (char *)arg);
}

int main (int argc, char *argv[]) {
    printf("current pid:%d\n",getpid());

    struct event_base *base = event_base_new ();
    if (!base) {
        printf ("new event base error\n");
        return -1;
    }

    struct event *ev = event_new (base, SIGUSR1, EV_SIGNAL|EV_PERSIST, signal_cb, "hello,world"); /* kill -USR1 21911 */
    if (!ev) {
        printf ("new event failed\n");
        return -1;
    }
    event_add (ev, NULL);

    event_base_dispatch (base);

    event_base_free (base);
    event_free (ev);

    return 0;
}
