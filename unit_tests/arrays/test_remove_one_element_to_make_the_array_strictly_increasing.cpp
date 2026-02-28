#include "arrays/remove_one_element_to_make_the_array_strictly_increasing.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt


TEST(CanBeIncreasing, TrivialSizes) {
    EXPECT_TRUE(canBeIncreasing(vector<int>{}));
    EXPECT_TRUE(canBeIncreasing(vector<int>{5}));
    EXPECT_TRUE(canBeIncreasing(vector<int>{5, 5})); // size <= 2 => true by this implementation
    EXPECT_TRUE(canBeIncreasing(vector<int>{1, 2}));
}

TEST(CanBeIncreasing, AlreadyStrictlyIncreasing) {
    EXPECT_TRUE(canBeIncreasing(vector<int>{1, 2, 3, 4}));
    EXPECT_TRUE(canBeIncreasing(vector<int>{-5, -1, 0, 7, 10}));
    EXPECT_TRUE(canBeIncreasing(vector<int>{1, 3, 10}));
}

TEST(CanBeIncreasing, OneRemovalWorks_RemoveBadElement) {
    EXPECT_TRUE(canBeIncreasing(vector<int>{1, 2, 10, 3, 4})); // remove 10
    EXPECT_TRUE(canBeIncreasing(vector<int>{1, 2, 3, 2, 4}));  // remove 2 at i=3
    EXPECT_TRUE(canBeIncreasing(vector<int>{1, 5, 2, 3, 4}));  // remove 5
}

TEST(CanBeIncreasing, DuplicateHandling) {
    EXPECT_TRUE(canBeIncreasing(vector<int>{1, 2, 2, 3}));   // remove one 2
    EXPECT_FALSE(canBeIncreasing(vector<int>{1, 2, 2, 2}));  // need >1 removal
    EXPECT_FALSE(canBeIncreasing(vector<int>{3, 3, 3}));     // cannot fix with 1 removal
}

TEST(CanBeIncreasing, MustReturnFalse_WhenTwoViolations) {
    EXPECT_FALSE(canBeIncreasing(vector<int>{1, 2, 1, 2}));
    EXPECT_FALSE(canBeIncreasing(vector<int>{5, 4, 3, 2, 1}));
    EXPECT_FALSE(canBeIncreasing(vector<int>{1, 3, 2, 2}));
    EXPECT_FALSE(canBeIncreasing(vector<int>{1, 2, 5, 3, 2, 6}));
}

TEST(CanBeIncreasing, EdgeCasesAroundIminus2Rule) {
    EXPECT_TRUE(canBeIncreasing(vector<int>{1, 2, 3, 1, 4}));
    EXPECT_FALSE(canBeIncreasing(vector<int>{10, 1, 2, 3, 0}));
    EXPECT_TRUE(canBeIncreasing(vector<int>{1, 2, 10, 3, 5}));
}

TEST(CanBeIncreasing, NegativeAndMixedValues) {
    EXPECT_TRUE(canBeIncreasing(vector<int>{-3, -2, -1, -1, 0}));
    EXPECT_FALSE(canBeIncreasing(vector<int>{0, -1, -2}));
    EXPECT_TRUE(canBeIncreasing(vector<int>{-10, -5, -6, -3}));
}