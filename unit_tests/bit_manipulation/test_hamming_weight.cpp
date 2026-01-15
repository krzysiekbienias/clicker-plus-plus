#include "bit_manipulation/hamming_weight.hpp"

#include <gtest/gtest.h>


TEST(HammingWeight,TrivalCase)
{
    std::cout<<std::bitset<8>(6)<<std::endl;
    EXPECT_EQ(hammingWeight(6),2);
}

TEST(HammingWeight,Zero)
{
    EXPECT_EQ(hammingWeight(0),0);
}
