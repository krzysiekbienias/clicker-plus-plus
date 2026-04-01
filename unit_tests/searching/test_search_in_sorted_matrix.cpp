# include <gtest/gtest.h>
#include "searching/search_in_sorted_matrix.hpp"

TEST(SearchInSortedArray,BasicCase)
{
    std::vector<std::vector<int>> matrix{
            {1, 4, 7, 12, 15, 1000},
            {2, 5, 19, 31, 32, 1001},
            {3, 8, 24, 33, 35, 1002},
            {40, 41, 42, 44, 45, 1003},
            {99, 100, 103, 106, 128, 1004},
          };
    std::vector<int> expected{3, 3};
    std::vector<int> actual=searchInSortedMatrix(matrix,44);
    EXPECT_EQ(actual,expected);
}

TEST(SearchInSortedArray,NoSearch)
{
    std::vector<std::vector<int>> matrix{
                {1, 4, 7, 12, 15, 1000},
                {2, 5, 19, 31, 32, 1001},
                {3, 8, 24, 33, 35, 1002},
                {40, 41, 42, 44, 45, 1003},
                {99, 100, 103, 106, 128, 1004},
              };
    std::vector<int> expected{-1, -1};
    std::vector<int> actual=searchInSortedMatrix(matrix,2000);
    EXPECT_EQ(actual,expected);
}