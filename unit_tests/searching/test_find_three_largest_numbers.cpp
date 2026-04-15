#include <gtest/gtest.h>
#include "searching/find_three_largest_numbers.hpp"

TEST(BigThree,TrivalCase)
{   std::vector<int> input ={141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7};
    std::vector<int> actual =findThreeLargestNumbers(input);
    std::vector<int> expected={18,141,541};

    EXPECT_EQ(actual,expected);

}