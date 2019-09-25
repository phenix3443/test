/* -*- coding:utf-8; -*- */
/* 测试cmockery测试代码架构 */
#include <assert.h>
#include <stdbool.h>

#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>

#include <google/cmockery.h> /* 注意该头文件依赖上面三个头文件，注意顺序 */

void empty_test (void **state) {}

int main (int argc, char *argv[]) {
    const UnitTest tests[] = {
        unit_test (empty_test),
    };
    return run_tests (tests);
}
