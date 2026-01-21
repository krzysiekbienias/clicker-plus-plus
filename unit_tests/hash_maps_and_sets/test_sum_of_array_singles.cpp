#include "hash_maps_and_sets/sum_of_array_singles.hpp"
#include <gtest/gtest.h>
TEST(Repeats, SampleCases)
{
    EXPECT_EQ(sumOfArraySingles(std::vector<int>{4, 5, 7, 5, 4, 8}), 15);
    EXPECT_EQ(sumOfArraySingles(std::vector<int>{9, 10, 19, 13, 19, 13}), 19);
    EXPECT_EQ(sumOfArraySingles(std::vector<int>{16, 0, 11, 4, 8, 16, 0, 11}), 12);
    EXPECT_EQ(sumOfArraySingles(std::vector<int>{5, 17, 18, 11, 13, 18, 11, 13}), 22);
}