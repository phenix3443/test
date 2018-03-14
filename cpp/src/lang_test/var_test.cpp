// -*- coding:utf-8 -*-
// author:liushangliang
// desc: 变量测试

#include "lang_test.hpp"

int global_var;

class Person {
public:
        std::string name;
};

void test()
{
        int local_var;
        Person p = Person();
        EXPECT_EQ (0, global_var);
        EXPECT_NE (0, local_var);
        EXPECT_EQ("", p.name);
}

TEST (VarTest, DefalutInit) {
        test();
}
