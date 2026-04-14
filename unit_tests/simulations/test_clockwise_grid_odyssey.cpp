#include "simulations/clockwise_grid_odyssey.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

TEST(ClockwiseGridOdyssey, SingleElementGrid) {
    int rows = 1, cols = 1, rStart = 0, cStart = 0;
    std::vector<std::vector<int>> expected = {{0, 0}};

    std::vector<std::vector<int>> actual = clockwiseGridOdyssey(rows, cols, rStart, cStart);
    EXPECT_EQ(actual, expected);
}

TEST(ClockwiseGridOdyssey, SmallGridTraversal) {
    // 2x2 grid starting at (0,0)
    // Path: (0,0) -> (0,1) -> (1,1) -> (1,0)
    int rows = 2, cols = 2, rStart = 0, cStart = 0;
    std::vector<std::vector<int>> expected = {
        {0, 0}, {0, 1}, {1, 1}, {1, 0}
    };

    std::vector<std::vector<int>> actual = clockwiseGridOdyssey(rows, cols, rStart, cStart);
    EXPECT_EQ(actual, expected);
}

TEST(ClockwiseGridOdyssey, ProvidedExampleCase) {
    int rows = 5;
    int cols = 6;
    int rStart = 1;
    int cStart = 4;

    std::vector<std::vector<int>> expected = {
        {1,4},{1,5},{2,5},{2,4},{2,3},{1,3},{0,3},{0,4},{0,5},{3,5},
        {3,4},{3,3},{3,2},{2,2},{1,2},{0,2},{4,5},{4,4},{4,3},{4,2},
        {4,1},{3,1},{2,1},{1,1},{0,1},{4,0},{3,0},{2,0},{1,0},{0,0}
    };

    std::vector<std::vector<int>> actual = clockwiseGridOdyssey(rows, cols, rStart, cStart);

    ASSERT_EQ(actual.size(), expected.size());
    for (size_t i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(actual[i], expected[i]) << "Mismatch at index " << i;
    }
}

TEST(ClockwiseGridOdyssey, OffCenterStart) {
    // 3x3 grid starting at (1,1)
    int rows = 3, cols = 3, rStart = 1, cStart = 1;
    // Spiral: (1,1) -> E: (1,2) -> N: (2,2) -> W: (2,1), (2,0) -> S: (1,0), (0,0) -> E: (0,1), (0,2)
    std::vector<std::vector<int>> expected = {
        {1, 1}, {1, 2}, {2, 2}, {2, 1}, {2, 0}, {1, 0}, {0, 0}, {0, 1}, {0, 2}
    };

    std::vector<std::vector<int>> actual = clockwiseGridOdyssey(rows, cols, rStart, cStart);
    EXPECT_EQ(actual, expected);
}