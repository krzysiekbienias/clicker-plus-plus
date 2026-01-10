#include "arrays/zero_sum_subarray.hpp"
#include <gtest/gtest.h>



TEST (ZeroSumSubarray,EmptyVec)
{
EXPECT_FALSE(zeroSumSubarray({}));
}

TEST (ZeroSumSubarray,TrivalCase)
{
    EXPECT_TRUE(zeroSumSubarray({-5,-5,2,3,-2}));
    EXPECT_TRUE(zeroSumSubarray({0}));
}

TEST (ZeroSumSubarray,TrivalCaseFalse)
{
    EXPECT_FALSE(zeroSumSubarray({1,2,3,4}));
    EXPECT_FALSE(zeroSumSubarray({4}));
}