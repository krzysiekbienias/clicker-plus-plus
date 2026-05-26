#include "bit_manipulation/reverse_bits.hpp"

#include <gtest/gtest.h>

TEST(ReverseBits,TrivalCase)
{
    EXPECT_EQ(reverseBits(6),1);
}