// -*- coding:utf-8 -*-
#include <iostream>

using namespace std;

void do_something () {}

void do_something_else () {}

void do_something_completely_different () {}

void q () {}
void w () {}
void r () {}

void test () {
    int x, y;
    switch (x) {
        case 0:
        case 1:
            do_something ();
            break;
        case 2:
            do_something_else ();
            break;
        default:
            break;
    }

    if (false) do_something_completely_different ();

    if (x == y) {
        q ();
    } else if (x > y) {
        w ();
    } else {
        r ();
    }
}

int main (int argc, char *argv[]) {
    test ();
    return 0;
}
