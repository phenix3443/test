// -*- coding:utf-8 -*-
// author:liushangliang
// desc: class 测试
#include <iostream>

#include "lang_test.hpp"

class Base {
public:
        virtual void func() {
                std::cout << "in base" << std::endl;
        };
};

class Derived : public Base{

};

TEST(ClassTest, VirtualTest) {
        Base b;
        Derived d;
        d.func();
}
