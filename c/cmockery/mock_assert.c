/* -*- coding:utf-8; -*- */
#include <assert.h>
#include <stdbool.h>

#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>

#include <google/cmockery.h> /* 注意该头文件依赖上面三个头文件，注意顺序 */

void assert_success (void **state) { assert (true); }

void assert_failed (void **state) { assert (false); }

int main (int argc, char *argv[]) {
    const UnitTest tests[] = {
        unit_test (assert_success),
        unit_test (assert_failed),
    };
    return run_tests (tests);
}
