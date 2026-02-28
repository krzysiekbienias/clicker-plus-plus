#include "two_pointers/remove_element_from_array.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt


// Helper: compare only first k elements
static std::vector<int> firstK(const std::vector<int>& v, int k) {
    return std::vector<int>(v.begin(), v.begin() + k);
}

TEST(RemoveElement, EmptyVector_ReturnsZero) {
    std::vector<int> nums{};
    int k = removeElement(nums, 7);
    EXPECT_EQ(k, 0);
    EXPECT_TRUE(nums.empty());
}

TEST(RemoveElement, NoElementMatches_VectorUnchanged) {
    std::vector<int> nums{1, 2, 3, 4};
    int k = removeElement(nums, 9);
    EXPECT_EQ(k, 4);
    EXPECT_EQ(firstK(nums, k), (std::vector<int>{1, 2, 3, 4}));
}

TEST(RemoveElement, AllElementsMatch_ReturnsZero_FirstKEmpty) {
    std::vector<int> nums{5, 5, 5};
    int k = removeElement(nums, 5);
    EXPECT_EQ(k, 0);
    EXPECT_EQ(firstK(nums, k), (std::vector<int>{}));
}

TEST(RemoveElement, RemovesSomeElements_PreservesOrder) {
    std::vector<int> nums{3, 2, 2, 3};
    int k = removeElement(nums, 3);
    EXPECT_EQ(k, 2);
    EXPECT_EQ(firstK(nums, k), (std::vector<int>{2, 2}));
}

TEST(RemoveElement, RemovesFromMiddle) {
    std::vector<int> nums{1, 2, 3, 2, 4};
    int k = removeElement(nums, 2);
    EXPECT_EQ(k, 3);
    EXPECT_EQ(firstK(nums, k), (std::vector<int>{1, 3, 4}));
}

TEST(RemoveElement, RemovesAtEnds) {
    std::vector<int> nums{7, 1, 2, 3, 7};
    int k = removeElement(nums, 7);
    EXPECT_EQ(k, 3);
    EXPECT_EQ(firstK(nums, k), (std::vector<int>{1, 2, 3}));
}

TEST(RemoveElement, SingleElement_NotRemoved) {
    std::vector<int> nums{42};
    int k = removeElement(nums, 7);
    EXPECT_EQ(k, 1);
    EXPECT_EQ(firstK(nums, k), (std::vector<int>{42}));
}

TEST(RemoveElement, SingleElement_Removed) {
    std::vector<int> nums{7};
    int k = removeElement(nums, 7);
    EXPECT_EQ(k, 0);
    EXPECT_EQ(firstK(nums, k), (std::vector<int>{}));
}

TEST(RemoveElement, HandlesNegativeAndZero) {
    std::vector<int> nums{0, -1, 0, 2, 0, -3};
    int k = removeElement(nums, 0);
    EXPECT_EQ(k, 3);
    EXPECT_EQ(firstK(nums, k), (std::vector<int>{-1, 2, -3}));
}