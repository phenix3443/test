/* -*- coding:utf-8; -*- */
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>

#include <google/cmockery.h> /* 注意该头文件依赖上面三个头文件，注意顺序 */

void test_success (void **state) {}

int main (int argc, char *argv[]) {
    const UnitTest tests[] = {
        unit_test (test_success),
    };
    return run_tests (tests);
}
