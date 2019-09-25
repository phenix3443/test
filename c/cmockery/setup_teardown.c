/* -*- coding:utf-8; -*- */
/* 测试set-up 和tear-down */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>

#include <google/cmockery.h> /* 注意该头文件依赖上面三个头文件，注意顺序 */

bool flag = false;
bool *p_flag = &flag;

void test_success (void **state) {}

void test_failure (void **state) {}

void set_up (void **state) {
    *state = (void *)&p_flag;
    *((bool *)*state) = true;
    printf ("set-up end flag=%s\n", flag ? "true" : "false");
}

void tear_down (void **state) {
    *((bool *)*state) = false;
    printf ("tear-down end flag=%s\n", flag ? "true" : "false");
}

int main (int argc, char *argv[]) {
    const UnitTest tests[] = {
        unit_test_setup_teardown (test_success, set_up, tear_down),
        unit_test_setup_teardown (test_failure, set_up, tear_down),
        /* unit_test (test_success), */
        /* unit_test (test_failure), */
    };
    return run_tests (tests);
}
