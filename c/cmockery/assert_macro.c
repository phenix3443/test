/* -*- coding:utf-8; -*- */
/* 测试assert_* 系列的宏 */
#include <assert.h>
#include <stdbool.h>

#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>

#include <google/cmockery.h> /* 注意该头文件依赖上面三个头文件，注意顺序 */

void test_int_equal (void **state) { assert_int_equal (1, 2); }

int main (int argc, char *argv[]) {
    const UnitTest tests[] = {
        unit_test (test_int_equal),

    };
    return run_tests (tests);
}
