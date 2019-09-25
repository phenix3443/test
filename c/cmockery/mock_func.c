/* -*- coding:utf-8; -*- */
/* 测试mock fucntion以及返回值 */
#include <assert.h>
#include <stdbool.h>

#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>

#include <google/cmockery.h> /* 注意该头文件依赖上面三个头文件，注意顺序 */

/* 函数f是对 g搜所依赖函数的一个模拟*/
bool f (int a) { return (bool)mock (); }

/* 函数g依赖函数f */
int g (int b) {
    bool ret = f (b);
    return ret;
}

void test_success (void **state) {
    will_return (f, true);
    assert_true (g (2));
}

void test_failure (void **state) {
    will_return (f, false);
    assert_true (g (2));
}

int main (int argc, char *argv[]) {
    const UnitTest tests[] = {
        unit_test (test_success),
        unit_test (test_failure),

    };
    return run_tests (tests);
}
