#include <gtest/gtest.h>

#include "searching/index_equal_value.hpp"


TEST(IndexEqualValue,BaseCase)
{
    std::vector<int> input = {-5, -3, 0, 3, 4, 5, 9};
    int actual=indexEqualValue(input);
    EXPECT_EQ(actual,3);
}

// Test when the fixed point is at the very first index
TEST(IndexEqualValue, FirstElement)
{
    std::vector<int> input = {0, 2, 3, 4, 5};
    EXPECT_EQ(indexEqualValue(input), 0);
}

// Test when the fixed point is at the very last index
TEST(IndexEqualValue, LastElement)
{
    std::vector<int> input = {-2, -1, 0, 1, 4};
    EXPECT_EQ(indexEqualValue(input), 4);
}

// Test with a single-element vector (Success)
TEST(IndexEqualValue, SingleElementSuccess)
{
    std::vector<int> input = {0};
    EXPECT_EQ(indexEqualValue(input), 0);
}

// Test when no index matches its value
TEST(IndexEqualValue, NoMatch)
{
    std::vector<int> input = {-5, -4, 3, 4, 5};
    EXPECT_EQ(indexEqualValue(input), -1);
}

// Test with an empty vector
TEST(IndexEqualValue, EmptyInput)
{
    std::vector<int> input = {};
    EXPECT_EQ(indexEqualValue(input), -1);
}

// Test when multiple indices satisfy the condition
// Depending on your requirements, you likely want the first occurrence (2)
TEST(IndexEqualValue, MultipleMatches)
{
    std::vector<int> input = {-1, 0, 2, 3, 4, 10};
    EXPECT_EQ(indexEqualValue(input), 2);
}