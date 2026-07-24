#include "combinatorics/count_distinct_substrings.hpp"
#include <gtest/gtest.h>

#include <string>

// countDistinct: liczba roznych (distinct) podciagow ciaglych stringa.

TEST(CountDistinctSubstrings, EmptyString) {
    EXPECT_EQ(countDistinct(""), 0);
}

TEST(CountDistinctSubstrings, SingleChar) {
    EXPECT_EQ(countDistinct("a"), 1);
}

TEST(CountDistinctSubstrings, TwoSameChars) {
    // "a", "aa"
    EXPECT_EQ(countDistinct("aa"), 2);
}

TEST(CountDistinctSubstrings, ThreeSameChars) {
    // "a", "aa", "aaa"
    EXPECT_EQ(countDistinct("aaa"), 3);
}

TEST(CountDistinctSubstrings, AllDistinctChars) {
    // n=3, wszystkie n(n+1)/2 = 6 podciagow rozne
    EXPECT_EQ(countDistinct("abc"), 6);
}

TEST(CountDistinctSubstrings, PalindromeWithRepeat) {
    // "aba": a, ab, aba, b, ba  -> 5 (a powtorzone)
    EXPECT_EQ(countDistinct("aba"), 5);
}

TEST(CountDistinctSubstrings, RepeatingPattern) {
    // "abab": a, ab, aba, abab, b, ba, bab -> 7
    EXPECT_EQ(countDistinct("abab"), 7);
}

TEST(CountDistinctSubstrings, TwoDistinctChars) {
    // "ab": a, ab, b -> 3
    EXPECT_EQ(countDistinct("ab"), 3);
}

TEST(CountDistinctSubstrings, MixedRepeats) {
    // "abcabc": znane distinct = 15
    EXPECT_EQ(countDistinct("abcabc"), 15);
}
