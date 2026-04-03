#include "dynamic_programming/max_sum_increasing_subsequence.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"
#include <gmock/gmock.h>

using ::testing::ElementsAre;

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

TEST(MaxSumIncreasingSubsequence,BaseCase)
{
    std::vector<int> input{10, 70, 20, 30, 50, 11, 30};
    std::vector<std::vector<int>> expected{{110}, {10, 20, 30, 50}};

    std::vector<std::vector<int>> actual=maxSumIncreasingSubsequence(input);
    EXPECT_THAT(actual,expected);


}