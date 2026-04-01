#include "two_pointers/the_next_permutation.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

TEST(NextPermutationTest, BasicIncreasingCase) {
    std::vector<int> nums = {1, 2, 3};
    EXPECT_EQ(nextPermutation(nums), (std::vector<int>{1, 3, 2}));
}

TEST(NextPermutationTest, BasicMixedCase) {
    std::vector<int> nums = {1, 3, 2};
    EXPECT_EQ(nextPermutation(nums), (std::vector<int>{2, 1, 3}));
}

TEST(NextPermutationTest, DescendingOrderBecomesSmallest) {
    std::vector<int> nums = {3, 2, 1};
    EXPECT_EQ(nextPermutation(nums), (std::vector<int>{1, 2, 3}));
}

TEST(NextPermutationTest, TwoElementsIncreasing) {
    std::vector<int> nums = {1, 2};
    EXPECT_EQ(nextPermutation(nums), (std::vector<int>{2, 1}));
}

TEST(NextPermutationTest, TwoElementsDecreasing) {
    std::vector<int> nums = {2, 1};
    EXPECT_EQ(nextPermutation(nums), (std::vector<int>{1, 2}));
}

TEST(NextPermutationTest, SingleElementRemainsSame) {
    std::vector<int> nums = {5};
    EXPECT_EQ(nextPermutation(nums), (std::vector<int>{5}));
}

TEST(NextPermutationTest, PivotNearEnd) {
    std::vector<int> nums = {1, 2, 4, 3};
    EXPECT_EQ(nextPermutation(nums), (std::vector<int>{1, 3, 2, 4}));
}

TEST(NextPermutationTest, PivotInMiddle) {
    std::vector<int> nums = {1, 4, 3, 2};
    EXPECT_EQ(nextPermutation(nums), (std::vector<int>{2, 1, 3, 4}));
}

TEST(NextPermutationTest, WithDuplicatesSimple) {
    std::vector<int> nums = {1, 1, 5};
    EXPECT_EQ(nextPermutation(nums), (std::vector<int>{1, 5, 1}));
}

TEST(NextPermutationTest, WithDuplicatesAnotherCase) {
    std::vector<int> nums = {1, 5, 1};
    EXPECT_EQ(nextPermutation(nums), (std::vector<int>{5, 1, 1}));
}

TEST(NextPermutationTest, AllElementsEqual) {
    std::vector<int> nums = {2, 2, 2};
    EXPECT_EQ(nextPermutation(nums), (std::vector<int>{2, 2, 2}));
}

TEST(NextPermutationTest, DuplicateValuesDescendingSuffix) {
    std::vector<int> nums = {1, 2, 2, 3};
    EXPECT_EQ(nextPermutation(nums), (std::vector<int>{1, 2, 3, 2}));
}

TEST(NextPermutationTest, LargerDuplicateCase) {
    std::vector<int> nums = {2, 2, 0, 4, 3, 1};
    EXPECT_EQ(nextPermutation(nums), (std::vector<int>{2, 2, 1, 0, 3, 4}));
}

TEST(NextPermutationTest, EntireSequenceNeedsReset) {
    std::vector<int> nums = {9, 7, 5, 3, 1};
    EXPECT_EQ(nextPermutation(nums), (std::vector<int>{1, 3, 5, 7, 9}));
}

TEST(NextPermutationTest, SuffixNeedsFullReverseAfterSwap) {
    std::vector<int> nums = {1, 3, 5, 4, 2};
    EXPECT_EQ(nextPermutation(nums), (std::vector<int>{1, 4, 2, 3, 5}));
}