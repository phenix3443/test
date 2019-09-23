/* -*- coding:utf-8; -*- */
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>

#include <google/cmockery.h>

void test_success (void **state) {}

int main (int argc, char *argv[]) {
    const UnitTest tests[] = {
        unit_test (test_success),
    };
    return run_tests (tests);
}
