/* -*- coding:utf-8; -*- */
/* 测试使用mock_assert替代标准库assert函数 */
#include <assert.h>
#include <stdbool.h>

#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>

#include <google/cmockery.h> /* 注意该头文件依赖上面三个头文件，注意顺序 */

#if UNIT_TESTING
extern void mock_assert (const int result, const char *const expression,
                         const char *const file, const int line);
#undef assert
#define assert(expression) \
    mock_assert ((int)(expression), #expression, __FILE__, __LINE__);
#endif  // UNIT_TESTING

void f () { assert (true); }
void g () { assert (false); }

void test_success (void **state) { assert (true); }
void test_failure (void **state) { assert (false); }

int main (int argc, char *argv[]) {
    const UnitTest tests[] = {
        unit_test (test_success),
        unit_test (test_failure),
    };
    return run_tests (tests);
}
