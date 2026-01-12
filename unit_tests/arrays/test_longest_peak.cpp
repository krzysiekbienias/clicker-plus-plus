#include "arrays/longest_peak.hpp"
#include <gtest/gtest.h>

TEST(LongestPeak,EmptyVec)
{   std::vector<int> v1={};
    EXPECT_EQ(longestPeak(v1),0);
}


TEST(LongestPeak,Basic)
{   std::vector<int> v1={1,2,3,3,4,0,10,6,5,-1,-3,2,3};
    EXPECT_EQ(longestPeak(v1),6);
}

TEST(LongestPeak,OnlyIncrease)
//no peak because there is no decreasing part.
{   std::vector<int> v1={1,2,6,10};
    EXPECT_EQ(longestPeak(v1),0);
}

TEST(LongestPeak,Platou)
//no peak because there is no decreasing part.
{   std::vector<int> v1={1,2,6,6};
    EXPECT_EQ(longestPeak(v1),0);
}

TEST(LongestPeak,AlgoExperFail)
//no peak because there is no decreasing part.
{   std::vector<int> v1={1,1,3,2,1};
    EXPECT_EQ(longestPeak(v1),4);
}