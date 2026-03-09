#include "hash_maps_and_sets/longest_unit_gap_subsequence.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

TEST(FindLHSTest, ExampleCaseOne) {
    std::vector<int> nums{1, 3, 2, 2, 5, 2, 3, 7};
    EXPECT_EQ(findLHS(nums), 5);
}

TEST(FindLHSTest, ExampleCaseTwo) {
    std::vector<int> nums{1, 2, 3, 4};
    EXPECT_EQ(findLHS(nums), 2);
}

TEST(FindLHSTest, ExampleCaseThreeNoHarmoniousSubsequence) {
    std::vector<int> nums{1, 1, 1, 1};
    EXPECT_EQ(findLHS(nums), 0);
}

TEST(FindLHSTest, EmptyArrayReturnsZero) {
    std::vector<int> nums{};
    EXPECT_EQ(findLHS(nums), 0);
}

TEST(FindLHSTest, SingleElementReturnsZero) {
    std::vector<int> nums{42};
    EXPECT_EQ(findLHS(nums), 0);
}

TEST(FindLHSTest, TwoElementsDifferenceOne) {
    std::vector<int> nums{4, 5};
    EXPECT_EQ(findLHS(nums), 2);
}

TEST(FindLHSTest, TwoElementsSameValueReturnsZero) {
    std::vector<int> nums{7, 7};
    EXPECT_EQ(findLHS(nums), 0);
}

TEST(FindLHSTest, AllElementsCanBeUsed) {
    std::vector<int> nums{1, 2, 2, 1, 2, 1};
    EXPECT_EQ(findLHS(nums), 6);
}

TEST(FindLHSTest, ChoosesLargestAdjacentFrequencyPair) {
    std::vector<int> nums{1, 1, 2, 2, 2, 3, 3};
    EXPECT_EQ(findLHS(nums), 5); // pair (1,2) => 2+3=5, pair (2,3) => 3+2=5
}

TEST(FindLHSTest, MultipleCandidatesPickBestOne) {
    std::vector<int> nums{1, 1, 1, 2, 2, 3, 3, 3, 3};
    EXPECT_EQ(findLHS(nums), 6); // best is (2,3) => 2+4=6
}

TEST(FindLHSTest, NegativeNumbersWorkCorrectly) {
    std::vector<int> nums{-2, -1, -1, -1, 0, 1};
    EXPECT_EQ(findLHS(nums), 4); // pair (-2,-1) => 1+3=4, pair (-1,0) => 3+1=4
}

TEST(FindLHSTest, MixedNegativeAndPositiveValues) {
    std::vector<int> nums{-1, 0, 0, 0, 1, 1, 2};
    EXPECT_EQ(findLHS(nums), 5); // pair (0,1) => 3+2=5
}

TEST(FindLHSTest, NonContiguousSubsequenceStillCounts) {
    std::vector<int> nums{10, 100, 11, 200, 10, 11, 300};
    EXPECT_EQ(findLHS(nums), 4); // pair (10,11) => 2+2=4
}

TEST(FindLHSTest, LargeDuplicateBlockWithNoNeighborReturnsZero) {
    std::vector<int> nums{8, 8, 8, 8, 8, 8};
    EXPECT_EQ(findLHS(nums), 0);
}

TEST(FindLHSTest, PairMustDifferByExactlyOneNotMore) {
    std::vector<int> nums{1, 1, 3, 3, 3};
    EXPECT_EQ(findLHS(nums), 0);
}

TEST(FindLHSTest, UnsortedInputHandledCorrectly) {
    std::vector<int> nums{4, 2, 1, 2, 3, 3, 2, 4, 5};
    EXPECT_EQ(findLHS(nums), 5); // best is (2,3) => 3+2=5 or (3,4) => 2+2=4
}

TEST(FindLHSTest, BestPairAppearsLateInCounting) {
    std::vector<int> nums{1, 2, 2, 5, 5, 5, 6, 6, 6, 6};
    EXPECT_EQ(findLHS(nums), 7); // pair (5,6) => 3+4=7
}

TEST(FindLHSTest, IntegerExtremesStillValidWhenNeighborExists) {
    std::vector<int> nums{INT_MIN, INT_MIN + 1, INT_MIN + 1};
    EXPECT_EQ(findLHS(nums), 3);
}