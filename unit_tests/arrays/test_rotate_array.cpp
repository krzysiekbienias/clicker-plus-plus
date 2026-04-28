#include "arrays/rotate_array.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

TEST(RotateWithExtraArrayTest, BasicRotation) {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;
    std::vector<int> expected = {4, 5, 1, 2, 3};

    rotateWithExtraArray(nums, k);
    EXPECT_EQ(nums, expected);
}

TEST(RotateWithExtraArrayTest, RotateByFullLength) {
    std::vector<int> nums = {1, 2, 3};
    int k = 3;
    std::vector<int> expected = {1, 2, 3};

    rotateWithExtraArray(nums, k);
    EXPECT_EQ(nums, expected);
}

TEST(RotateWithExtraArrayTest, RotateByLargeK) {
    // Normalization check: k = 7 on size 5 is equivalent to k = 2
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int k = 7;
    std::vector<int> expected = {4, 5, 1, 2, 3};

    rotateWithExtraArray(nums, k);
    EXPECT_EQ(nums, expected);
}

TEST(RotateWithExtraArrayTest, SingleElement) {
    std::vector<int> nums = {10};
    int k = 5;
    std::vector<int> expected = {10};

    rotateWithExtraArray(nums, k);
    EXPECT_EQ(nums, expected);
}

TEST(RotateWithExtraArrayTest, EmptyVector) {
    std::vector<int> nums = {};
    int k = 3;
    std::vector<int> expected = {};

    // This tests the guard clause at the start of your function
    rotateWithExtraArray(nums, k);
    EXPECT_EQ(nums, expected);
}

TEST(RotateWithExtraArrayTest, ZeroRotation) {
    std::vector<int> nums = {1, 2, 3, 4};
    int k = 0;
    std::vector<int> expected = {1, 2, 3, 4};

    rotateWithExtraArray(nums, k);
    EXPECT_EQ(nums, expected);
}