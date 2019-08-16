/* -*- coding:utf-8; -*- */
/* socket地址相关测试 */

#include <arpa/inet.h> /* 大小端系列函数，地址转换函数 */
#include <stdio.h>

static inline void order () {
    printf ("host order: %04x\n", 0x0102); /* 小端 */
    printf ("net order: %04x\n", htons (0x0102));
}

static inline void addr_str () {
    struct in_addr addr;

    if (inet_pton (AF_INET, "127.0.0.1", (void *)&addr.s_addr) == 1) {
        printf ("addr bin: %0x\n", addr.s_addr);
    }

    char dot[INET_ADDRSTRLEN];
    printf ("addr dot: %s\n",
            inet_ntop (AF_INET, (void *)&addr.s_addr, dot, INET_ADDRSTRLEN));
}

int main (int argc, char *argv[]) {
    order ();
    addr_str ();
    return 0;
}
