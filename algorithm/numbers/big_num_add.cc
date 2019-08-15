#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include <gtest\gtest.h>

namespace phenix3443 {
    //建立进制对应的哈希表
    std::shared_ptr<std::map<char, short>> Map_10 () {
        auto r_map = std::make_shared<std::map<char, short>> ();

        for (int i = 0; i < 10; ++i) {
            (*r_map)['0' + i] = i;
        }
        return r_map;
    }
    std::shared_ptr<std::map<char, short>> Map_16 () {
        auto r_map = std::make_shared<std::map<char, short>> ();

        for (int i = 0; i < 10; ++i) {
            (*r_map)['0' + i] = i;
        }
        for (int i = 10; i < 16; ++i) {
            (*r_map)['A' + i - 10] = i;
        }
        return r_map;
    }
    std::map<short, std::function<std::shared_ptr<std::map<char, short>> ()>>
        build_randix_map = {
            {10, Map_10},
            {16, Map_16},
    };
    //将 std::string 表示的大数存放在 std::vector<short>中
    inline void str_to_vc (const std::string &str, std::vector<short> &vs,
                           const int base = 10) {
        auto r_map = build_randix_map[base]();

        std::function<bool(const char &)> f = [&](const char &c) {
            return (*r_map).count (c) != 0;
        };
        auto first_dig = find_if (str.begin (), str.end (), f);
        auto last_dig = find_if_not (first_dig, str.end (), f);
        auto sign_at = find (str.begin (), first_dig, '-');
        short sign = (sign_at != first_dig) ? -1 : 1;

        for_each (first_dig, last_dig,
                  [&](const char &e) { vs.push_back (sign * ((*r_map)[e])); });
    }
    //将 std::vector<short>中存放的大数放回 std::string 中
    inline void vc_to_str (const std::vector<short> &vs, std::string &str,
                           const int base = 10) {
        auto r_map = build_randix_map[base]();
        std::map<short, char> tmp_map;
        for (auto &e : *r_map) tmp_map.insert ({e.second, e.first});
        for_each (vs.begin (), vs.end (), [&](const short &e) {
            str.push_back (tmp_map[(e + base) % base]);
        });
        if (vs[0] < 0) str.insert (str.begin (), '-');
    }

    //大整数加法
    //考虑： 1.有效输入，包含正负号，字符串中非数字字符,字符串开始的连续空格，
    //      2.存放的数据结构 std::vector 与 std::string
    //      3.如何处理进位
    //      4.随意输入大数字的长度大小
    //      5.进制

    //知识点：1.字符与数字之间的转换
    //       2.const 在参数列表处的使用
    //       3.STL 算法库使用 find 系列 for_each
    //       4.lamda 函数的使用，值捕获与引用捕获
    //       5.负数取模运算

    int BigSum (const std::string &num1, const std::string &num2,
                std::string &sum, const int base = 10) {
        assert (!num1.empty () && !num2.empty () && sum.empty ());
        //将 std::string 每一位转换为 voctor<short>对应的数字
        std::vector<short> vbig, vsmall;

        str_to_vc (num1, vbig);
        str_to_vc (num2, vsmall);

        // 保证 vbig 保存了较大的数
        if (vbig.size () < vsmall.size ()) swap (vbig, vsmall);
        // vbig vsmall 按位累加，不考虑进位
        std::vector<short> vsum (vbig.size (), 0);
        for (int i = vbig.size () - 1, j = vsmall.size () - 1; i >= 0; --i) {
            vsum[i] = vbig[i] + ((j >= 0) ? vsmall[j--] : 0);
        }
        // 处理进位
        for (int i = vsum.size () - 1; i >= 0; --i) {
            if (vsum[i] > base) {
                vsum[i] -= base;
                if (i > 0)
                    ++vsum[i - 1];
                else
                    vsum.insert (vsum.begin (), 1);
            }
        }
        //第一步的逆转换vc_to_str(vsum, sum);
        return 0;
    }

    TEST (TestBigSum, mul) {
        std::string a = "-2222";
        std::string b = "1111";
        std::string sum;
        BigSum (b, a, sum);
        EXPECT_STREQ ("-9999", sum.c_str ());
    }
}  // namespace phenix3443
