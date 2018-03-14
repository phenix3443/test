// -*- coding:utf-8 -*-
// author:liushangliang
// desc: 语言特性整体描述

#include <iostream>

int global_var = 0;

int main(int argc, char *argv[])
{
        bool b = true;
        void* ptr = nullptr;

        char cv = 'a';           // 字符
        signed char scv = L'a'; // 字面量前缀，char有三种类型
        unsigned char ucv = 'a'; //


        short sv = {-1};        // 列表初始化
        unsigned short usv = 024; // 八进制

        int iv{-1};             // 列表初始化
        unsigned int uiv = 0x24; // 十六进制

        long lv(-1L);             // 字面量后缀
        unsigned long ulv = 24UL; // 字面量后缀

        long long llv = -1LL;
        unsigned long long ullv = 1ULL;

        float f;                 // 默认初始化
        double d = 3.14;
        long double ld = 0;

        const char* str = u8"Hello,world"; // 字面量前缀

        std::cout << "in" " one" "line" << std::endl;

        std::cout << "in"
                "two" "line" << std::endl; // 字符串分行

        std::cout << '\115'  << '\x4d' << '\n'; // 转义字符

        return 0;
}
