// -*- coding:utf-8 -*-
// author:liushangliang
// desc: 跳转语句测试

#include "lang_test.hpp"


TEST(ControlTest, IF_ELSEIF_ELSE) {
        int var = 0;
        if (var == 1) {
                std::cout << 1 << std::endl;
        } else if (var ==2 ) {
                std::cout << 2 << std::endl;
        } else {
                std::cout << "other" << std::endl;
        }

}
