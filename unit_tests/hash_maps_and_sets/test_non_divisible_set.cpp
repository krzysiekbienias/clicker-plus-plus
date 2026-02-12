#include "hash_maps_and_sets/non_divisible_set.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt


TEST(NonDivisibleSet,TrivalCase1)
{
    std::vector<int> v={19,10,12,11,17,24,25,22,6,8,3,7,15};
    int actual=nonDivisibleSubset(4,v);
    EXPECT_EQ(actual,7);
}