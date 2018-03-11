# -*- coding:utf-8; -*-
# author: liushangliang
# desc: 控制语句测试

import unittest


class ControlTest(unittest.TestCase):
    def testIF(self):
        var = 1
        if var == 1:
            print(1)
        elif var == 2:
            print(2)
        else:
            print(3)


if __name__ == "__main__":
    unittest.main()
