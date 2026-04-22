#include "math_and_geometry/largest_triangle_perimeter.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

TEST(LargestPerimeterTest, StandardValidTriangle) {
    std::vector<int> nums{2, 1, 2};
    // Sorted: 1, 2, 2 -> 1+2 > 2 is true. Perimeter = 5
    EXPECT_EQ(largestPerimeter(nums), 5);
}

TEST(LargestPerimeterTest, NoPossibleTriangle) {
    std::vector<int> nums{1, 2, 1};
    // Sorted: 1, 1, 2 -> 1+1 > 2 is false.
    EXPECT_EQ(largestPerimeter(nums), 0);
}

TEST(LargestPerimeterTest, LargestPossibleSelection) {
    std::vector<int> nums{3, 6, 2, 3};
    // Sorted: 2, 3, 3, 6
    // Check 3,3,6: 3+3 > 6 is false
    // Check 2,3,3: 2+3 > 3 is true. Perimeter = 8
    EXPECT_EQ(largestPerimeter(nums), 8);
}

TEST(LargestPerimeterTest, LargeInputSet) {
    std::vector<int> nums{10, 1, 10, 2, 5, 20, 30};
    // Sorted: 1, 2, 5, 10, 10, 20, 30
    // 10, 20, 30: 10+20 > 30 (False)
    // 10, 10, 20: 10+10 > 20 (False)
    // 5, 10, 10: 5+10 > 10 (True). Perimeter = 25
    EXPECT_EQ(largestPerimeter(nums), 25);
}

TEST(LargestPerimeterTest, MinimumSizeArray) {
    std::vector<int> nums{5, 5, 5};
    EXPECT_EQ(largestPerimeter(nums), 15);
}

TEST(LargestPerimeterTest, AllElementsSame) {
    std::vector<int> nums{100, 100, 100, 100};
    EXPECT_EQ(largestPerimeter(nums), 300);
}