#include "heap/merge_sorted_arrays.hpp"
#include <gtest/gtest.h>


TEST(MergeSortedArray,BasicCase)
{
    std::vector<std::vector<int>> arrays = {
        {1, 5, 9, 21},
        {-1, 0},
        {-124, 81, 121},
        {3, 6, 12, 20, 150},
      };
    std::vector<int> expected{-124, -1, 0, 1, 3, 5, 6, 9, 12, 20, 21, 81, 121, 150};
    std::vector<int> actual=mergeSortedArrays(arrays);



}