// 理解typedef时候直接替换是错误的
TEST (BuildinTypeTest, TypedefTest) {
    typedef std::string *pstring;
    std::string s = "hello,world";
    const pstring ps = &s;
    // ps = std::string("change"); // ps类型并不是const string *
    *ps = "change";  // 而是 string * const
}
