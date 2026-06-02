#include "greedy/minimize_product_sum.hpp"
#include <gtest/gtest.h>

TEST(MinimizeProductSum, ExampleFromProblem_FirstCase) {
    std::vector<int> nums1{5, 3, 4, 2};
    std::vector<int> nums2{4, 2, 2, 5};
    // optimal pairing: [2,3,4,5] with [5,4,2,2] -> 40
    EXPECT_EQ(minProductSum(nums1, nums2), 40);
}

TEST(MinimizeProductSum, ExampleFromProblem_SecondCase) {
    std::vector<int> nums1{2, 1, 4, 5, 7};
    std::vector<int> nums2{3, 2, 4, 8, 6};
    // optimal pairing: [1,2,4,5,7] with [8,6,4,3,2] -> 65
    EXPECT_EQ(minProductSum(nums1, nums2), 65);
}

TEST(MinimizeProductSum, SingleElement) {
    std::vector<int> nums1{7};
    std::vector<int> nums2{3};
    EXPECT_EQ(minProductSum(nums1, nums2), 21);
}

TEST(MinimizeProductSum, TwoElements_GreedyBeatsNaiveOrder) {
    std::vector<int> nums1{4, 1};
    std::vector<int> nums2{2, 3};
    // pair [1,4] with [3,2] -> 1*3 + 4*2 = 11 (not 1*2 + 4*3 = 14)
    EXPECT_EQ(minProductSum(nums1, nums2), 11);
}

TEST(MinimizeProductSum, AllOnes) {
    std::vector<int> nums1{1, 1, 1};
    std::vector<int> nums2{1, 1, 1};
    EXPECT_EQ(minProductSum(nums1, nums2), 3);
}

TEST(MinimizeProductSum, WithNegativeValues) {
    std::vector<int> nums1{-1, 2};
    std::vector<int> nums2{3, -2};
    // pair [-1, 2] with [3, -2] -> -3 + (-4) = -7
    EXPECT_EQ(minProductSum(nums1, nums2), -7);
}

TEST(MinimizeProductSum, EmptyArrays) {
    std::vector<int> nums1{};
    std::vector<int> nums2{};
    EXPECT_EQ(minProductSum(nums1, nums2), 0);
}

TEST(MinimizeProductSum, IdenticalArrays) {
    std::vector<int> nums1{1, 2, 3};
    std::vector<int> nums2{1, 2, 3};
    // pair [1,2,3] with [3,2,1] -> 1*3 + 2*2 + 3*1 = 10
    EXPECT_EQ(minProductSum(nums1, nums2), 10);
}
