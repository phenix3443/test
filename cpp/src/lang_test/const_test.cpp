// -*- coding:utf-8 -*-
// author:liushangliang
// desc: const测试

#include "lang_test.hpp"

TEST (ConstTest, ConstVar) {
        const int var = 10;
        int* ptr = const_cast<int*>(&var);
        *ptr = 20;

        std::cout << var << " " << *ptr << std::endl; //此处编译器使用常量直接进行了替代
        EXPECT_EQ (&var, ptr) << "var 与 ptr地址不一致" << std::endl;
        EXPECT_EQ (var, 10) << "var is " << var << std::endl;
        EXPECT_EQ (*ptr, 20) << "ptr is " << *ptr << std::endl;

        struct Test {
                int var_;
                Test():var_(10){ }
        };
        const Test t;
        auto p_var = &Test::var_; // 数据成员指针
        auto ptr2 = const_cast<int*>(&(t.*p_var));
        *ptr2 = 20;

        std::cout << t.var_ << " " << *ptr2 << std::endl;
        EXPECT_EQ (&t.var_, ptr2) << "t.var_ 与 ptr2 地址不一致" << std::endl;
        EXPECT_EQ (t.var_, 20) << "t.var_ is " << t.var_ << std::endl;
        EXPECT_EQ (*ptr2, 20) << "ptr2 is " << ptr2 << std::endl;
}
