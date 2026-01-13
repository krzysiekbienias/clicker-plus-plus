#include "dynamic_programming/lis.hpp"

#include <gtest/gtest.h>

TEST(LISLen,EmptyVec)
{
    std::vector<int> empty{};
    EXPECT_EQ(longestIncreasingSubsequenceLen(empty),0);
}

TEST(LISLen,StrictlyIncreasing)
{
    std::vector<int> v={1,2,3,4};
    EXPECT_EQ(longestIncreasingSubsequenceLen(v),4);
}

TEST(LISLen,StrictlyDecreasing)
{
    std::vector<int> v={4,3,2,1};
    EXPECT_EQ(longestIncreasingSubsequenceLen(v),1);
}


TEST(LISLen,UdemyExample)
{
    std::vector<int> v={7,5,2,4,7,2,3,6,4,5,12,1,7};
    EXPECT_EQ(longestIncreasingSubsequenceLen(v),1);
}