#include "heap/merge_sorted_arrays.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

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