#include "arrays/max_consecutive_ones.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt


TEST(MaxConsecutiveOnes,Base)
{
    int actual =findMaxConsecutiveOnes({1,1,0,1,1,1});

}

TEST(FindMaxConsecutiveOnes, EmptyVector_ReturnsZero) {
    std::vector<int> nums{};
    EXPECT_EQ(findMaxConsecutiveOnes(nums), 0);
}

TEST(FindMaxConsecutiveOnes, SingleElement) {
    EXPECT_EQ(findMaxConsecutiveOnes({0}), 0);
    EXPECT_EQ(findMaxConsecutiveOnes({1}), 1);
}

TEST(FindMaxConsecutiveOnes, AllZeros_ReturnsZero) {
    EXPECT_EQ(findMaxConsecutiveOnes({0,0,0,0}), 0);
}

TEST(FindMaxConsecutiveOnes, AllOnes_ReturnsSize) {
    EXPECT_EQ(findMaxConsecutiveOnes({1,1,1,1,1}), 5);
}

TEST(FindMaxConsecutiveOnes, Alternating_ReturnsOne) {
    EXPECT_EQ(findMaxConsecutiveOnes({1,0,1,0,1,0}), 1);
    EXPECT_EQ(findMaxConsecutiveOnes({0,1,0,1,0,1}), 1);
}

TEST(FindMaxConsecutiveOnes, TypicalMixedCases) {
    EXPECT_EQ(findMaxConsecutiveOnes({1,1,0,1,1,1}), 3);
    EXPECT_EQ(findMaxConsecutiveOnes({0,1,1,1,0,1,1}), 3);
    EXPECT_EQ(findMaxConsecutiveOnes({1,0,1,1,0,1}), 2);
}

TEST(FindMaxConsecutiveOnes, MaxRunAtBeginningMiddleEnd) {
    EXPECT_EQ(findMaxConsecutiveOnes({1,1,1,0,1}), 3);          // beginning
    EXPECT_EQ(findMaxConsecutiveOnes({0,1,1,1,0}), 3);          // middle
    EXPECT_EQ(findMaxConsecutiveOnes({0,1,0,1,1,1,1}), 4);      // end
}

TEST(FindMaxConsecutiveOnes, LongRunWithMultipleBreaks) {
    EXPECT_EQ(findMaxConsecutiveOnes({1,1,0,1,1,1,0,1,1}), 3);
    EXPECT_EQ(findMaxConsecutiveOnes({0,0,1,1,1,1,0,1,1,1}), 4);
}