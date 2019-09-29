/* -*- coding:utf-8; -*- */

#include <assert.h>
#include <stdbool.h>

#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>

#include <google/cmockery.h> /* 注意该头文件依赖上面三个头文件，注意顺序 */

/**
 * @fn  empty_test
 * 
 * @brief      function description
 *
 * @details    detailed description
 *
 * @param      param
 *
 * @return     return type
 */
void empty_test (void **state) {}

int main (int argc, char *argv[]) {
    const UnitTest tests[] = {
        unit_test (empty_test), /*!< 空测试 */
    };
    return run_tests (tests);
}
