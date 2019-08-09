// -*- coding:utf-8 -*-
// author:liushangliang
// desc: 跳转语句测试

#include "lang_test.hpp"


TEST(BuildinTypeTest, AutoConvert) {
        EXPECT_TRUE(1);
        EXPECT_FALSE(0);

        EXPECT_EQ(1, true);
        EXPECT_EQ(0, false);

        int i = 3.24;
        EXPECT_EQ(3, i);

        int d = 3;
        EXPECT_DOUBLE_EQ(3.0, d);

        unsigned char uc = 257;
        EXPECT_EQ(1, uc);

        signed char sc = 128;
        EXPECT_EQ(1,sc);

        unsigned u = 10, u2 = 42; // unsigned int
        EXPECT_EQ(32, u-u2);
}

TEST(BuildinTypeTest, ReferTest) {
        int x = 1;
        int y = 2;              // 为什么要多声明一个变量呢
        int &b = x;
        printf("&x=%x,&y=%x,&b=%x,b=%x\n",&x,&y,&y-1,*(&y-1));
}

TEST(BuildinTypeTest, TypedefTest) {
        typedef std::string *pstring;
        std::string s = "hello,world";
        const pstring ps = &s;
        // ps = std::string("change"); // ps类型并不是const string *
        *ps = "change";             // 而是 string * const

}
