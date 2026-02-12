#include <gtest/gtest.h>

#include"combinatorics/vowels_of_all_substrings.hpp"


TEST(VowelsInSubstrings,TrivalCase)
{
    std::string s="aba";
    int actual=countVowelsOptimal(s);
    EXPECT_EQ(actual,6);
}