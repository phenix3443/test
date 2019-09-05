/*-*- coding:utf-8 -*- */
/* 测试sizeof 操作符 */
#include <stdio.h>

int main (int argc, char *argv[]) {
    int a = 1;
    char b = 2;
    /* printf ("%lu\n", sizeof int);* wrong */
    printf ("%lu\n", sizeof (int)); /* 4 */
    printf ("%lu\n", sizeof b); /* 1 */
    printf ("%lu\n", sizeof (a = b + 1)); /* 4 */
    printf ("%d\n", a); /* 1 */
    return 0;
}
