/* -*- coding:utf-8; -*- */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFSIZE 4096

int main (int argc, char *argv[]) {
    char buf[BUFFSIZE];
    int n;
    while ((n = read (STDIN_FILENO, buf, BUFFSIZE)) > 0) {
        if ((write (STDOUT_FILENO, buf, n)) != n) {
            printf ("write error\n");
            exit (1);
        }
    }
    if (n < 0) {
        printf ("read error\n");
        exit (1);
    }

    return 0;
}
