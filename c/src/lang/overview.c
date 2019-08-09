// -*- coding:utf-8 -*-
// author:liushangliang
// desc: 语言特性整体描述

#include <stdio.h>

int global_var = 0;

int main(int argc, char *argv[])
{
        void * ptr = NULL;

        char cv = 'a';
        signed char scv = -1;
        unsigned char ucv = L'a';

        short sv = -1;
        unsigned short usv = 024;

        int iv = -1;
        unsigned int uiv = 0x24;

        long lv = -1L;
        unsigned long ulv = 24UL;

        long long llv = -1LL;
        unsigned long long ullv = 1ULL;

        float fv = 0.1f;
        double d = 3.14;

        printf("Hello,world!\n");
        return 0;
}
