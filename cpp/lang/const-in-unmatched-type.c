/* 当const变量被不同类型赋值，实际上指向了临时变量 */
TEST (ConstTest, ConstRefer) {
    double d = 3.214;
    const int &r = d;
    std::cout << "&d=" << &d << " &r=" << &r << std::endl;
}
