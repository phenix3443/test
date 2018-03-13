// -*- coding:utf-8 -*-
// author:liushangliang
// desc: 语言特性整体描述
#include <iostream>

int glocal_var = 0;

int main(int argc, char *argv[])
{
        bool b = true;
        void* ptr = nullptr;

        char c = 'a';
        signed char sc = L'a';
        unsigned char usc = 'a';

        short s = -1;
        unsigned short uss = 024;

        int i = -1;
        unsigned int usi = 0x24;

        long l = -1L;
        unsigned long usl = 24UL;

        long long ll = -1LL;
        unsigned long long ull = -1ULL;

        float f = 0l;
        double d = 3.14;
        long double ld = 0;

        const char* str = u8"Hello,world";

        std::cout << "in" " one" "line" << std::endl;

        std::cout << "in"
                "two" "line" << std::endl;

        std::cout << '\115'  << '\x4d' << '\n';

        return 0;
}
