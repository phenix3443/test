/* coding:utf-8 */
#include <stdio.h>

void foo(int n) {
    int vla[n];
    printf("vlna size=%lu\n", sizeof(vla));
}

int main(int argc, char *argv[])
{
    foo(3);
    return 0;
}
