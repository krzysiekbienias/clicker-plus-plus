#include <gtest/gtest.h>

#include <math_and_geometry/pascal_triangle.hpp>



TEST(PascalTriangle, ZeroRows_ReturnsEmpty) {
    auto tri = generatePascalTriangle(0);
    EXPECT_TRUE(tri.empty());
}

TEST(PascalTriangle, OneRow) {
    auto tri = generatePascalTriangle(1);
    std::vector<std::vector<int>> expected = {
        {1}
    };
    EXPECT_EQ(tri, expected);
}

TEST(PascalTriangle, TwoRows) {
    auto tri = generatePascalTriangle(2);
    std::vector<std::vector<int>> expected = {
        {1},
        {1, 1}
    };
    EXPECT_EQ(tri, expected);
}

TEST(PascalTriangle, FiveRows) {
    auto tri = generatePascalTriangle(5);
    std::vector<std::vector<int>> expected = {
        {1},
        {1, 1},
        {1, 2, 1},
        {1, 3, 3, 1},
        {1, 4, 6, 4, 1}
    };
    EXPECT_EQ(tri, expected);
}

TEST(PascalTriangle, ShapeAndEdges_AreOnes) {
    int n = 6;
    auto tri = generatePascalTriangle(n);

    ASSERT_EQ((int)tri.size(), n);
    for (int r = 0; r < n; ++r) {
        ASSERT_EQ((int)tri[r].size(), r + 1);
        EXPECT_EQ(tri[r].front(), 1);
        EXPECT_EQ(tri[r].back(), 1);
    }
}

TEST(PascalTriangle, InternalValues_AreSumOfTwoAbove) {
    int n = 7;
    auto tri = generatePascalTriangle(n);

    for (int r = 2; r < n; ++r) {
        for (int c = 1; c < r; ++c) {
            EXPECT_EQ(tri[r][c], tri[r - 1][c - 1] + tri[r - 1][c]);
        }
    }
}