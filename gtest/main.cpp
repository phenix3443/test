#include <gtest/gtest.h>
#include <iostream>

extern int MyDiv(int,int);

TEST(MyDivTest, Dived0) {
        EXPECT_EQ(1, MyDiv(1, 2));
}

int main(int argc, char *argv[])
{
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}
