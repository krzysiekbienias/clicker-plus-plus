#include "sliding_window/longest_increasing_continuous_subsequence.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

TEST(LICS,StrictlyIncreasing)
{
    int actual=findLengthOfLCIS({1,2,3,4,5,6});
    int expected=6;

    EXPECT_EQ(actual,expected);
}


TEST(LICS,Constant)
{
    int actual=findLengthOfLCIS({2,2,2,2,2,2});
    int expected=1;//one elemet sequence

    EXPECT_EQ(actual,expected);
}


TEST(LICS,Base)
{
    int actual=findLengthOfLCIS({1,3,5,4,7});
    int expected=3;//one elemet sequence

    EXPECT_EQ(actual,expected);
}