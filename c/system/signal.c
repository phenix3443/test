/* -*- coding:utf-8;-*- */
/* signal函数测试 */

#include <stdio.h>

#include <unistd.h>

#include <signal.h>

static void handle_user (int sig) {
    printf ("received signal %d\n", sig);
    if (sig == SIGUSR1) {
        printf ("received usr1 signal\n");
    } else if (sig == SIGUSR2) {
        printf ("received usr2 signal\n");
    }
}

int main (int argc, char *argv[]) {
    printf ("pid: %d\n", getpid ());

    if (signal (SIGUSR1, handle_user) == SIG_ERR) {
        printf ("can not catch SIGUSR1\n");
        return 1;
    }
    if (signal (SIGUSR2, handle_user) == SIG_ERR) {
        printf ("can not catch SIGUSR2\n");
        return 1;
    }
    while (1) {
        pause ();
    }
    return 0;
}
