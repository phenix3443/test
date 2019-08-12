/* -*- coding:utf-8 -*- */
/* 函数strcmp的原型是int strcmp(const char *s1,const char *s2)。 */
/* 若 s1==s2，返回零； */
/* 若 s1>s2，返回正数； */
/* 若 s1<s2，返回负数。 */
/* 即：两个字符串自左向右逐个字符相比（按 ASCII
 * 值大小相比较），直到出现不同的字符或遇\0为止。 */
#include <assert.h>
#include <stdio.h>

int strcmp (const char *s1, const char *s2) {
    assert ((s1 != NULL) && (s2 != NULL));
    while (*s1 == *s2) {
        if (*s1 == '\0') return 0;

        ++s1;
        ++s2;
    }
    return *s1 - *s2;
}
