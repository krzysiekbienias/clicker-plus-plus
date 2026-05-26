#include "numbers_theory/divisible_by_60.hpp"
#include <gtest/gtest.h>



TEST (DivisibleBy60,TrivalCase)
{
    std::vector<int> t1={2,0,5,1,1};
    auto res=divisibleBy60(t1);
    EXPECT_TRUE(res);
}

TEST (DivisibleBy60,twoDigits)
{
    std::vector<int> t1={4,0};
    auto res=divisibleBy60(t1);
    EXPECT_FALSE(res);
}