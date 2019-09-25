/* -*- coding:utf-8; -*- */
/* 测试expect_assert_failure使用 */

#include <assert.h>
#include <stdbool.h>

#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>

#include <google/cmockery.h> /* 注意该头文件依赖上面三个头文件，注意顺序 */

void f () {}
void g () { assert_true (true); }
void h () { assert_true (false); }

void test_success (void **state) { expect_assert_failure (f); }
void test_failure (void **state) { expect_assert_failure (g); }
void test_failure_2 (void **state) { expect_assert_failure (h); }

int main (int argc, char *argv[]) {
    const UnitTest tests[] = {
        unit_test (test_success),
        unit_test (test_failure),
        unit_test (test_failure_2),
    };
    return run_tests (tests);
}
