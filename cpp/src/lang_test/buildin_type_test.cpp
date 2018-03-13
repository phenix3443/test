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
