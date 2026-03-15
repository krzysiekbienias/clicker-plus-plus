#include "dynamic_programming/longest_palindromic_subsequence.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

TEST(LongestPalindromicSubsequence,TrivalCase)
{
    int actual=longestPalindromeSubseq("babcbab");
    int expected=7;
    EXPECT_EQ(actual,expected);
}

TEST(LongestPalindromicSubsequence, SingleCharacter)
{
    int actual = longestPalindromeSubseq("a");
    int expected = 1;
    EXPECT_EQ(actual, expected);
}

TEST(LongestPalindromicSubsequence, TwoEqualCharacters)
{
    int actual = longestPalindromeSubseq("aa");
    int expected = 2;
    EXPECT_EQ(actual, expected);
}

TEST(LongestPalindromicSubsequence, TwoDifferentCharacters)
{
    int actual = longestPalindromeSubseq("ab");
    int expected = 1;
    EXPECT_EQ(actual, expected);
}

TEST(LongestPalindromicSubsequence, SimpleOddPalindrome)
{
    int actual = longestPalindromeSubseq("aba");
    int expected = 3;
    EXPECT_EQ(actual, expected);
}

TEST(LongestPalindromicSubsequence, SimpleEvenPalindrome)
{
    int actual = longestPalindromeSubseq("abba");
    int expected = 4;
    EXPECT_EQ(actual, expected);
}

TEST(LongestPalindromicSubsequence, LeetCodeExample1)
{
    int actual = longestPalindromeSubseq("bbbab");
    int expected = 4;
    EXPECT_EQ(actual, expected);
}

TEST(LongestPalindromicSubsequence, LeetCodeExample2)
{
    int actual = longestPalindromeSubseq("cbbd");
    int expected = 2;
    EXPECT_EQ(actual, expected);
}

TEST(LongestPalindromicSubsequence, NoRepeatedCharacters)
{
    int actual = longestPalindromeSubseq("abcd");
    int expected = 1;
    EXPECT_EQ(actual, expected);
}

TEST(LongestPalindromicSubsequence, FullPalindrome)
{
    int actual = longestPalindromeSubseq("racecar");
    int expected = 7;
    EXPECT_EQ(actual, expected);
}

TEST(LongestPalindromicSubsequence, SubsequenceNotSubstring)
{
    int actual = longestPalindromeSubseq("agbdba");
    int expected = 5; // abdba
    EXPECT_EQ(actual, expected);
}

TEST(LongestPalindromicSubsequence, RepeatedCharacters)
{
    int actual = longestPalindromeSubseq("aaaa");
    int expected = 4;
    EXPECT_EQ(actual, expected);
}

TEST(LongestPalindromicSubsequence, MixedCaseExample)
{
    int actual = longestPalindromeSubseq("character");
    int expected = 5; // carac
    EXPECT_EQ(actual, expected);
}