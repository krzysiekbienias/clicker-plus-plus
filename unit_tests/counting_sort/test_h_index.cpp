#include "counting_sort/h_index.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

TEST(HIndex,TrivalCase)
{
    std::vector<int> citations={3,0,6,1,5};
    int actual=hIndex(citations);
    EXPECT_EQ(actual,3);

}

TEST(HIndex,TrivalCase2)
{
    std::vector<int> citations={1,3,1};
    int actual=hIndex(citations);
    EXPECT_EQ(actual,1);

}