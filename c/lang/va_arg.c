/* -*- coding:utf-8; -*- */
/* 函数变参测试 */

#include <stdarg.h>
#include <stdio.h>

void f (int n, ...) {
    printf (n);
    va_list va_args;
    va_start (va_args, n);
    va_end (va_args);
}

int g () { return 3.24; }

int main (int argc, char *argv[]) {
    /* f (1, 2, 3, 4, 5); */
    printf ("%d", g);
    return 0;
}
