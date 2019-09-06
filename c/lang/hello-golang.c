/* -*- coding:utf-8 -*- */
/* 语言整体描述 */

#include <stdio.h>

void say (char *message) { printf ("%s", message); }

char *message = "hello,world!\n";

int main (int argc, char *argv[]) {
    say (message);
    return 0;
}
