/*-*- coding:utf-8 -*- */
/* 逗号操作符用于精简while语句 */
#include <stdio.h>

int incr_i (int i) { return ++i; }

void complex (void) {
    int i = incr_i (0);
    while (i < 5) {
        printf ("%d\n", i);
        i = incr_i (i);
    }
}

void simple (void) {
    int i = 0;
    while (i = incr_i (i), i < 5) {
        printf ("%d\n", i);
    }
}
int main (int argc, char *argv[]) {
    /* simple (); */
    complex();
    return 0;
}
