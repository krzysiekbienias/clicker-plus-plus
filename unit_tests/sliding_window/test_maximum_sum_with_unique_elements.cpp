#include "sliding_window/maximum_sum_with_unique_elements.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt
using namespace std;

TEST(MaximumUniqueSubarrayTest, ExampleCase)
{
    vector<int> nums = {4, 2, 4, 5, 6};
    EXPECT_EQ(maximumUniqueSubarray(nums), 17); // {2,4,5,6}
}

TEST(MaximumUniqueSubarrayTest, AllElementsUnique)
{
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(maximumUniqueSubarray(nums), 15);
}

TEST(MaximumUniqueSubarrayTest, AllElementsSame)
{
    vector<int> nums = {5, 5, 5, 5};
    EXPECT_EQ(maximumUniqueSubarray(nums), 5);
}

TEST(MaximumUniqueSubarrayTest, DuplicateInMiddle)
{
    vector<int> nums = {1, 2, 3, 2, 5};
    EXPECT_EQ(maximumUniqueSubarray(nums), 10); // {3,2,5} or {1,2,3}
}

TEST(MaximumUniqueSubarrayTest, DuplicateAtBeginning)
{
    vector<int> nums = {7, 7, 1, 2, 3};
    EXPECT_EQ(maximumUniqueSubarray(nums), 13); // {7,1,2,3}
}

TEST(MaximumUniqueSubarrayTest, DuplicateAtEnd)
{
    vector<int> nums = {1, 2, 3, 4, 4};
    EXPECT_EQ(maximumUniqueSubarray(nums), 10); // {1,2,3,4}
}

TEST(MaximumUniqueSubarrayTest, AlternatingDuplicates)
{
    vector<int> nums = {1, 2, 1, 2, 1, 2};
    EXPECT_EQ(maximumUniqueSubarray(nums), 3); // {1,2}
}

TEST(MaximumUniqueSubarrayTest, SingleElement)
{
    vector<int> nums = {42};
    EXPECT_EQ(maximumUniqueSubarray(nums), 42);
}

TEST(MaximumUniqueSubarrayTest, LargerWindowAfterShrinking)
{
    vector<int> nums = {5, 2, 1, 2, 5, 2, 1, 2, 5};
    EXPECT_EQ(maximumUniqueSubarray(nums), 8); // {5,2,1}
}

TEST(MaximumUniqueSubarrayTest, WindowBecomesSingleElementAfterDuplicate)
{
    vector<int> nums = {100, 1, 2, 3, 1};
    EXPECT_EQ(maximumUniqueSubarray(nums), 106); // {100,1,2,3}
}