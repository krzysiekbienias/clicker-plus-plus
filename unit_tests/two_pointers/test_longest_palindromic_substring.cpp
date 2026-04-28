#include "two_pointers/longest_palindromic_substring.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

TEST (LongestPalindromicSubstring,BaseCaseOdd)
{
    std::string actual=longestPalindromicSubstringExplicite("abcba");
    EXPECT_EQ(actual,"abcba");

}

TEST (LongestPalindromicSubstring,EachLetterDifferent)
{
    std::string actual=longestPalindromicSubstringExplicite("abc");
    EXPECT_EQ(actual,"a");

}