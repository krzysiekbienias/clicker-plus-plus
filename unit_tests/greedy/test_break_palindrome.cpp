#include "greedy/break_palindrome.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

TEST(BreakPalindromeTest, SingleCharacterReturnsEmptyString) {
    EXPECT_EQ(breakPalindrome("a"), "");
}

TEST(BreakPalindromeTest, TwoSameCharacters) {
    EXPECT_EQ(breakPalindrome("aa"), "ab");
}

TEST(BreakPalindromeTest, AllAsOddLength) {
    EXPECT_EQ(breakPalindrome("aba"), "abb");
}

TEST(BreakPalindromeTest, AllAsEvenLength) {
    EXPECT_EQ(breakPalindrome("aaaa"), "aaab");
}

TEST(BreakPalindromeTest, ReplaceFirstNonAInLeftHalfEvenLength) {
    EXPECT_EQ(breakPalindrome("abccba"), "aaccba");
}

TEST(BreakPalindromeTest, ReplaceFirstNonAInLeftHalfOddLength) {
    EXPECT_EQ(breakPalindrome("aacaa"), "aacab");
}

TEST(BreakPalindromeTest, MiddleCharacterShouldNotBeTouchedInOddLengthPalindrome) {
    EXPECT_EQ(breakPalindrome("aaabaaa"), "aaabaab");
}

TEST(BreakPalindromeTest, LargerPalindromeWithEarlyNonA) {
    EXPECT_EQ(breakPalindrome("bbbbbb"), "abbbbb");
}

TEST(BreakPalindromeTest, NonAOnlyInSecondPositionOfLeftHalf) {
    EXPECT_EQ(breakPalindrome("aabbaa"), "aaabaa");
}

TEST(BreakPalindromeTest, AlreadyMinimalLeftHalfSoChangeLastCharacterToB) {
    EXPECT_EQ(breakPalindrome("aaaaaa"), "aaaaab");
}