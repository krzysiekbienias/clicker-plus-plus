#include "binary_search/cutting_ribbons.hpp"
#include <gtest/gtest.h>

#include <vector>

using std::vector;

// --------------------
// LeetCode-style examples
// --------------------
TEST(MaxRibbonLength, ClassicExample) {
    vector<int> ribbons = {9, 7, 5};
    EXPECT_EQ(maxLength(ribbons, 4), 4);
}

TEST(MaxRibbonLength, ClassicExampleK3) {
    vector<int> ribbons = {9, 7, 5};
    EXPECT_EQ(maxLength(ribbons, 3), 5);
}

// --------------------
// Single ribbon
// --------------------
TEST(MaxRibbonLength, SingleRibbonExactSplit) {
    vector<int> ribbons = {5};
    EXPECT_EQ(maxLength(ribbons, 5), 1);
}

TEST(MaxRibbonLength, SingleRibbonTwoPieces) {
    vector<int> ribbons = {5};
    EXPECT_EQ(maxLength(ribbons, 2), 2);
}

TEST(MaxRibbonLength, SingleRibbonImpossible) {
    vector<int> ribbons = {5};
    EXPECT_EQ(maxLength(ribbons, 6), 0);
}

// --------------------
// Impossible cases
// --------------------
TEST(MaxRibbonLength, ImpossibleNotEnoughTotalLength) {
    vector<int> ribbons = {1, 2};
    EXPECT_EQ(maxLength(ribbons, 4), 0);
}

TEST(MaxRibbonLength, ImpossibleLargeK) {
    vector<int> ribbons = {4};
    EXPECT_EQ(maxLength(ribbons, 5), 0);
}

// --------------------
// Equal lengths
// --------------------
TEST(MaxRibbonLength, AllSameLength) {
    vector<int> ribbons = {3, 3, 3};
    EXPECT_EQ(maxLength(ribbons, 9), 1);
}

TEST(MaxRibbonLength, AllSameLengthPartialUse) {
    vector<int> ribbons = {3, 3, 3};
    EXPECT_EQ(maxLength(ribbons, 3), 3);
}

// --------------------
// Small mixed cases
// --------------------
TEST(MaxRibbonLength, TwoRibbonsSmallK) {
    vector<int> ribbons = {1, 2};
    EXPECT_EQ(maxLength(ribbons, 3), 1);
}

TEST(MaxRibbonLength, TwoRibbonsK2) {
    vector<int> ribbons = {1, 2};
    EXPECT_EQ(maxLength(ribbons, 2), 1);
}

TEST(MaxRibbonLength, LargerPiecesPreferred) {
    vector<int> ribbons = {10, 10};
    EXPECT_EQ(maxLength(ribbons, 4), 5);
}

TEST(MaxRibbonLength, LargerPiecesPreferredK5) {
    vector<int> ribbons = {10, 10};
    EXPECT_EQ(maxLength(ribbons, 5), 3);
}

TEST(MaxRibbonLength, RemainderDiscarded) {
    vector<int> ribbons = {7, 5, 9};
    EXPECT_EQ(maxLength(ribbons, 4), 4);
}

TEST(MaxRibbonLength, ExactDivisionBoundary) {
    vector<int> ribbons = {8, 8, 8};
    EXPECT_EQ(maxLength(ribbons, 6), 4);
}
