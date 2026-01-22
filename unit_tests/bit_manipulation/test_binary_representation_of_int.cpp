#include "bit_manipulation/binary_representation_of_int.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::ElementsAre;

TEST(ShowBits, SmallPositive)
{
    EXPECT_THAT(showBits(6), ElementsAre(
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0
    ));
}


TEST(ShowBits, BasicTest1)
{
    EXPECT_THAT(showBits(211), ElementsAre(
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1
    ));
}

TEST(ShowBits, BasicTest2)
{
    EXPECT_THAT(showBits(-1), ElementsAre(
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    ));
}