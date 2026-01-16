#include "bit_manipulation/trailing_zeros.hpp"
#include <gtest/gtest.h>


TEST(TrailingZeros,TrivalCase)
{

    EXPECT_EQ(trailingZeros(8),3);
}

TEST(TrailingZeros,Easy)
{
    EXPECT_EQ(trailingZeros(40),3);

}


TEST(TrailingZeros,LastBit1)
{

    EXPECT_EQ(trailingZeros(7),0);
    EXPECT_EQ(trailingZeros(41),0);

}