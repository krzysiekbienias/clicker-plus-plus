#include "binary_search/count_negative_numbers_in_a_sorted_matrix.hpp"
#include <gtest/gtest.h>

#include <vector>

using std::vector;

// --------------------
// LeetCode examples
// --------------------
TEST(CountNegatives, ClassicGrid) {
    vector<vector<int>> grid = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3},
    };
    EXPECT_EQ(countNegatives(grid), 8);
}

TEST(CountNegatives, NoNegatives) {
    vector<vector<int>> grid = {{3, 2}, {1, 0}};
    EXPECT_EQ(countNegatives(grid), 0);
}

TEST(CountNegatives, MixedTwoByTwo) {
    vector<vector<int>> grid = {{1, -1}, {-1, -1}};
    EXPECT_EQ(countNegatives(grid), 3);
}

TEST(CountNegatives, SingleNegative) {
    vector<vector<int>> grid = {{-1}};
    EXPECT_EQ(countNegatives(grid), 1);
}

// --------------------
// Empty and single cells
// --------------------
TEST(CountNegatives, EmptyGrid) {
    vector<vector<int>> grid;
    EXPECT_EQ(countNegatives(grid), 0);
}

TEST(CountNegatives, EmptyRow) {
    vector<vector<int>> grid(1);
    EXPECT_EQ(countNegatives(grid), 0);
}

TEST(CountNegatives, SingleZero) {
    vector<vector<int>> grid = {{0}};
    EXPECT_EQ(countNegatives(grid), 0);
}

TEST(CountNegatives, SinglePositive) {
    vector<vector<int>> grid = {{5}};
    EXPECT_EQ(countNegatives(grid), 0);
}

// --------------------
// Zeros are not negatives
// --------------------
TEST(CountNegatives, ZerosThenNegatives) {
    vector<vector<int>> grid = {{5, 1, 0, 0, -1}};
    EXPECT_EQ(countNegatives(grid), 1);
}

TEST(CountNegatives, RowOfZeros) {
    vector<vector<int>> grid = {{0, 0, 0}, {0, 0, -2}};
    EXPECT_EQ(countNegatives(grid), 1);
}

// --------------------
// Whole rows
// --------------------
TEST(CountNegatives, AllNegative) {
    vector<vector<int>> grid = {{-1, -2, -3}, {-4, -5, -6}};
    EXPECT_EQ(countNegatives(grid), 6);
}

TEST(CountNegatives, LastColumnOnly) {
    vector<vector<int>> grid = {
        {8, 4, 2, -1},
        {7, 3, 1, -1},
        {6, 2, 0, -2},
    };
    EXPECT_EQ(countNegatives(grid), 3);
}

TEST(CountNegatives, OnePositiveRowThenAllNegative) {
    vector<vector<int>> grid = {
        {2, 1, 0},
        {-1, -2, -3},
        {-4, -5, -6},
    };
    EXPECT_EQ(countNegatives(grid), 6);
}
