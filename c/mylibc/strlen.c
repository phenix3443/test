/* -*- coding:utf-8 -*- */
#include <stdlib.h>
#include <assert.h>

size_t strlen(const char *str)
{
    assert(str != NULL);
    size_t len = 0;
    while((*str++) != '\0')  {
        ++len;
    }
    return len;
}
