#include "dynamic_programming/paint_house.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(PaintHouseTest, ClassicExample) {
    std::vector<std::vector<int>> costs = {
        {17, 2, 17},
        {16, 16, 5},
        {14, 3, 19},
    };

    EXPECT_EQ(minCost(costs), 10);
}

TEST(PaintHouseTest, SingleHouse) {
    std::vector<std::vector<int>> costs = {{5, 3, 7}};

    EXPECT_EQ(minCost(costs), 3);
}

TEST(PaintHouseTest, TwoHouses) {
    std::vector<std::vector<int>> costs = {
        {1, 5, 3},
        {2, 1, 4},
    };

    EXPECT_EQ(minCost(costs), 2);
}

TEST(PaintHouseTest, GreedyFailsGlobalMinimumTrap) {
    std::vector<std::vector<int>> costs = {
        {1, 2, 100},
        {1, 100, 100},
        {100, 100, 1},
    };

    EXPECT_EQ(minCost(costs), 4);
}

TEST(PaintHouseTest, EqualCostsInPreviousRow) {
    std::vector<std::vector<int>> costs = {
        {4, 2, 8},
        {3, 5, 1},
    };

    EXPECT_EQ(minCost(costs), 3);
}

TEST(PaintHouseTest, LongerRowAlternatingPattern) {
    std::vector<std::vector<int>> costs = {
        {7, 6, 2},
        {5, 8, 1},
        {12, 3, 4},
        {6, 9, 7},
    };

    EXPECT_EQ(minCost(costs), 16);
}
