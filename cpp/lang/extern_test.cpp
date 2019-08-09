#include "lang_test.hpp"
#include "extern_var.hpp"


TEST(VarTest, ExternTest) {
        EXPECT_EQ(1,extern_var);
}
