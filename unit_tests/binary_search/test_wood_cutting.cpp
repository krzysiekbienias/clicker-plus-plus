#include "binary_search/wood_cutting.hpp"
#include <gtest/gtest.h>

#include <vector>

using std::vector;

// --------------------
// Problem statement example
// --------------------
TEST(CuttingWood, StatementExample) {
    EXPECT_EQ(cuttingWood({2, 6, 3, 8}, 7), 3);
}

// --------------------
// Single tree
// --------------------
TEST(CuttingWood, SingleTreeExactCut) {
    EXPECT_EQ(cuttingWood({10}, 5), 5);
}

TEST(CuttingWood, SingleTreeZeroHeight) {
    EXPECT_EQ(cuttingWood({10}, 10), 0);
}

TEST(CuttingWood, SingleTreePartialCut) {
    EXPECT_EQ(cuttingWood({10}, 3), 7);
}

// --------------------
// Equal heights
// --------------------
TEST(CuttingWood, AllTreesSameHeight) {
    EXPECT_EQ(cuttingWood({5, 5, 5}, 6), 3);
}

TEST(CuttingWood, AllTreesSameHeightExactAtZero) {
    EXPECT_EQ(cuttingWood({4, 4, 4}, 12), 0);
}

// --------------------
// Edge k values
// --------------------
TEST(CuttingWood, KZeroAllowsMaxHeight) {
    EXPECT_EQ(cuttingWood({2, 6, 3, 8}, 0), 8);
}

TEST(CuttingWood, KOne) {
    EXPECT_EQ(cuttingWood({1, 2, 3}, 1), 2);
}

// --------------------
// Impossible / no valid height beyond default res
// --------------------
TEST(CuttingWood, ImpossibleReturnsInitialRes) {
    EXPECT_EQ(cuttingWood({1, 2}, 100), 0);
}

TEST(CuttingWood, ImpossibleSingleTree) {
    EXPECT_EQ(cuttingWood({5}, 20), 0);
}

// --------------------
// Classic small cases
// --------------------
TEST(CuttingWood, SmallMixedHeights) {
    EXPECT_EQ(cuttingWood({1, 2, 3, 4, 5}, 9), 1);
}

TEST(CuttingWood, CutEverythingAtHeightZero) {
    EXPECT_EQ(cuttingWood({3, 3, 3}, 9), 0);
}

TEST(CuttingWood, JustBelowTotalWood) {
    EXPECT_EQ(cuttingWood({10, 20, 30}, 59), 0);
}

TEST(CuttingWood, TotalWoodExactlyK) {
    EXPECT_EQ(cuttingWood({10, 20, 30}, 60), 0);
}
