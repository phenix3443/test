/* -*- coding:utf-8 -*- */
/* 函数strcat的原型是char* strcat(char* des, char* src)，des 和 src 所指内存区域不可以重叠且 des 必须有足够的空间来容纳 src 的字符串。 */
#include <assert.h>
#include <stdio.h>

char* strcat(char* dest, const char* src)
{
	assert((dest!=NULL) && (src!=NULL));
	char* address = dest;
	while(*dest != '\0') {
        ++dest;
    };
	while((*dest++ = *src++) != '\0');

	return address;
}
