#include "gtest/gtest.h"

#include "example.h"

TEST(TestSum, TwoPlusTwoEqualsFour) {
    EXPECT_EQ(sum(2,2),4);
}
