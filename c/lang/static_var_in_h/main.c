/* -*- coding:utf-8 -*- */
#include <stdio.h>

#include "lib.h"

extern void f ();
int main (int argc, char *argv[]) {
    i = 20;
    printf ("static var in main:%d\n", i); /* 20 */
    f (); /* 10 */
    return 0;
}
