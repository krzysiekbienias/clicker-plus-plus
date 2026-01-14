#include "gtest/gtest.h"
#include "matrix/is_within_bounds.hpp"
#include <vector>

using std::vector;


TEST(IsWithinBounds, EmptyMatrix_AllCoordinatesAreOut) {
    vector<vector<int>> m;
    EXPECT_FALSE(isWithinBounds(0, 0, m));
    EXPECT_FALSE(isWithinBounds(0, -1, m));
    EXPECT_FALSE(isWithinBounds(-1, 0, m));
    EXPECT_FALSE(isWithinBounds(10, 10, m));
}

TEST(IsWithinBounds, OneByOneMatrix_InAndOut) {
    vector<vector<int>> m{{42}};

    EXPECT_TRUE(isWithinBounds(0, 0, m));

    EXPECT_FALSE(isWithinBounds(-1, 0, m));
    EXPECT_FALSE(isWithinBounds(0, -1, m));
    EXPECT_FALSE(isWithinBounds(1, 0, m));
    EXPECT_FALSE(isWithinBounds(0, 1, m));
}

TEST(IsWithinBounds, RectangularMatrix_BordersAndCorners) {
    // 3x5
    vector<vector<int>> m(3, vector<int>(5, 0));

    // corners
    EXPECT_TRUE(isWithinBounds(0, 0, m));
    EXPECT_TRUE(isWithinBounds(0, 4, m));
    EXPECT_TRUE(isWithinBounds(2, 0, m));
    EXPECT_TRUE(isWithinBounds(2, 4, m));

    // edges just outside
    EXPECT_FALSE(isWithinBounds(-1, 0, m));
    EXPECT_FALSE(isWithinBounds(0, -1, m));
    EXPECT_FALSE(isWithinBounds(3, 0, m));
    EXPECT_FALSE(isWithinBounds(0, 5, m));
}

TEST(IsWithinBounds, SingleRowMatrix) {
    // 1x4
    vector<vector<int>> m{{1, 2, 3, 4}};

    EXPECT_TRUE(isWithinBounds(0, 0, m));
    EXPECT_TRUE(isWithinBounds(0, 3, m));

    EXPECT_FALSE(isWithinBounds(0, 4, m));
    EXPECT_FALSE(isWithinBounds(1, 0, m));
    EXPECT_FALSE(isWithinBounds(-1, 2, m));
}

TEST(IsWithinBounds, SingleColumnMatrix) {
    // 4x1
    vector<vector<int>> m{{1}, {2}, {3}, {4}};

    EXPECT_TRUE(isWithinBounds(0, 0, m));
    EXPECT_TRUE(isWithinBounds(3, 0, m));

    EXPECT_FALSE(isWithinBounds(4, 0, m));
    EXPECT_FALSE(isWithinBounds(2, 1, m));
    EXPECT_FALSE(isWithinBounds(-1, 0, m));
}

TEST(IsWithinBounds, NegativeIndices_AreAlwaysOut) {
    vector<vector<int>> m(2, vector<int>(3, 0));

    EXPECT_FALSE(isWithinBounds(-1, 0, m));
    EXPECT_FALSE(isWithinBounds(0, -1, m));
    EXPECT_FALSE(isWithinBounds(-5, -7, m));
}

TEST(IsWithinBounds, LargeIndices_AreOut) {
    vector<vector<int>> m(10, vector<int>(10, 0));

    EXPECT_FALSE(isWithinBounds(10, 0, m));   // r == nbRows
    EXPECT_FALSE(isWithinBounds(0, 10, m));   // c == nbCols
    EXPECT_FALSE(isWithinBounds(1000, 5, m));
    EXPECT_FALSE(isWithinBounds(5, 1000, m));
}

TEST(IsWithinBounds, JaggedMatrix_UsesFirstRowAsColumnCount) {
    // This test documents the current behavior: nbCols = matrix[0].size()
    // So (1,2) will be considered out even though row 1 has 3 columns.
    vector<vector<int>> m{
        {1},        // size 1
        {2, 3, 4}   // size 3
    };

    EXPECT_TRUE(isWithinBounds(1, 0, m));   // within nbCols=1
    EXPECT_FALSE(isWithinBounds(1, 1, m));  // would exist in row 1, but function returns false
    EXPECT_FALSE(isWithinBounds(1, 2, m));  // would exist in row 1, but function returns false
}

TEST(IsWithinBounds, FirstRowEmpty_NbColsZeroSoAllColumnsOut) {
    vector<vector<int>> m{
        {},         // first row empty => nbCols = 0
        {1, 2, 3}
    };

    EXPECT_FALSE(isWithinBounds(0, 0, m));
    EXPECT_FALSE(isWithinBounds(1, 0, m));
    EXPECT_FALSE(isWithinBounds(1, 2, m));
    EXPECT_FALSE(isWithinBounds(0, -1, m));
}

TEST(IsWithinBounds, MediumMatrix_SpotChecksInside) {
    vector<vector<int>> m(7, vector<int>(9, 1));

    EXPECT_TRUE(isWithinBounds(3, 4, m));
    EXPECT_TRUE(isWithinBounds(6, 8, m));
    EXPECT_TRUE(isWithinBounds(0, 8, m));
    EXPECT_TRUE(isWithinBounds(6, 0, m));

    EXPECT_FALSE(isWithinBounds(7, 0, m));
    EXPECT_FALSE(isWithinBounds(0, 9, m));
    EXPECT_FALSE(isWithinBounds(-1, 8, m));
    EXPECT_FALSE(isWithinBounds(6, -1, m));
}