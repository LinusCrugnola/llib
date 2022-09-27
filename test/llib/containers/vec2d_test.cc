#include <gtest/gtest.h>
#include "vec2d.h"

TEST(Vec2dTest, BasicAssertions) {
    // Expect equalitys.
    EXPECT_EQ(1, 1);
    EXPECT_EQ(0, 1);

    llib::printTest();
}