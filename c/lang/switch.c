/*-*- coding:utf-8 -*- */
/* 测试switch语句的执行流程 */
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 1;
    switch (i) {
    case 0:
        printf("0\n");
    case 1:
        printf("1\n");
    case 2:
        printf("2\n");
    default:
        printf("unknown\n");
    }
    return 0;
}
