// -*- coding:utf-8 -*-
// author:liushangliang
// desc: 语言特性整体描述

#include <iostream>
#include <cctype>
#include <vector>

int global_var;                 // 作用域，默认初始化

int main(int argc, char *argv[])
{
        bool b = true;
        void *ptr = nullptr;    // 空指针

        char cv = 'a';           // 字符
        signed char scv = L'a'; // 字面量前缀，char有三种类型
        unsigned char ucv = 'a'; //


        short sv = {-1};        // 列表初始化
        unsigned short usv = 024; // 八进制

        int iv{-1};             // 列表初始化
        unsigned int uiv = 0x24; // 十六进制

        long lv(-1L);             // 字面量后缀，列表初始化
        unsigned long ulv = 24UL; // 字面量后缀

        long long llv = -1LL;
        unsigned long long ullv = 1ULL;

        float f;                 // 默认初始化
        double d = 3.14;
        long double ld = 0;

        const char* str = u8"Hello,world"; // 字面量前缀，常量表达式

        std::string one_line = "in" " one" " line";

        std::string two_line = "in"
                " two" " line"; // 字符串分行

        std::cout << '\115'  << '\x4d' << '\n'; // 转义字符

        int &riv = iv;          // 引用，复合声明

        typedef char * pstring; //  类型别名
        using INT = int;

        for (auto &c : one_line) {
                c = std::toupper(c);
        }

        std::vector<int> vi = {1,2,3,4}; // 列表初始化

        auto &beg = begin(vi), &last = end(vi); // 迭代器。

        return 0;
}
