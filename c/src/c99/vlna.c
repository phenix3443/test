/* coding:utf-8 */
#include <stdio.h>

void foo(int n) {
    int vlna[n];
    printf("vlna size=%lu\n", sizeof(vlna));
}

int main(int argc, char *argv[])
{
    foo(3);
    return 0;
}
