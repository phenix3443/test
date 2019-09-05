/*-*- coding:utf-8 -*- */
/* 逗号操作符用于精简while语句 */
#include <stdio.h>

int count_1 (int val) {
    int c;
    for (c = 0; val != 0; val >>= 1) {
        val & 1 ? ++c : c;
    }
    return c;
}

int count_0 (int val) {
    int c;
    for (c = 0; val != 0; val >>= 1) {
        val & 1 ? c:++c;
    }
    return c;
}


int main (int argc, char *argv[]) {
    int i = 2;

    printf ("i=%d, c=%d\n", i, count_1 (i));
    printf ("i=%d, c=%d\n", i, count_0 (i));

    return 0;
}
