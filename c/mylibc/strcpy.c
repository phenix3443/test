/* -*- coding:utf-8 -*- */

#include <stdlib.h>
#include <assert.h>
char * strcpy(char *strDest, const char *strSrc)
{
    assert((strDest != NULL) &&(strSrc != NULL));
    char *address = strDest;
    while((*strDest++ = * strSrc++) != '\0');
    return address;
}
