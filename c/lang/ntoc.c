/* -*- coding:utf-8; -*- */
/*将十进制证书用字符打印处理啊 */
#include <stdio.h>

void print_n (int n) {
    int i = n / 10;
    if (i != 0) {
        print_n (i);
    }
    printf ("%c ", '0' + n % 10);
}

int main (int argc, char *argv[]) {
    print_n (123456);
    printf ("\n");
    return 0;
}
