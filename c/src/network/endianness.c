#include <stdio.h>


void byte_order() {
    union {
        short v;
        char a[2];
    } t;

    t.v = 0x0102;

    if(t.a[0] == 1 && t.a[1] == 2) {
        printf("big endian\n");
    }
    else {
        printf("little endian\n");
    }

}

int main(int argc, char *argv[])
{
    byte_order();
    return 0;
}
