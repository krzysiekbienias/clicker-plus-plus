#include "hash_maps_and_sets/count_the_number_of_special_characters1.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(NumberOfSpecialChars, EmptyString_ReturnsZero) {
    EXPECT_EQ(numberOfSpecialChars(""), 0);
}

TEST(NumberOfSpecialChars, SingleLowercase_ReturnsZero) {
    EXPECT_EQ(numberOfSpecialChars("a"), 0);
}

TEST(NumberOfSpecialChars, SingleUppercase_ReturnsZero) {
    EXPECT_EQ(numberOfSpecialChars("Z"), 0);
}

TEST(NumberOfSpecialChars, OnlyLowercase_ReturnsZero) {
    EXPECT_EQ(numberOfSpecialChars("abc"), 0);
}

TEST(NumberOfSpecialChars, OnlyUppercase_ReturnsZero) {
    EXPECT_EQ(numberOfSpecialChars("ABC"), 0);
}

TEST(NumberOfSpecialChars, RepeatedSameCase_ReturnsZero) {
    EXPECT_EQ(numberOfSpecialChars("aaa"), 0);
    EXPECT_EQ(numberOfSpecialChars("BBB"), 0);
}

TEST(NumberOfSpecialChars, AdjacentPair_ReturnsOne) {
    EXPECT_EQ(numberOfSpecialChars("aA"), 1);
    EXPECT_EQ(numberOfSpecialChars("Aa"), 1);
}

TEST(NumberOfSpecialChars, LeetCodeExample1_ReturnsThree) {
    // aaAbcBC -> a/A, b/B, c/C
    EXPECT_EQ(numberOfSpecialChars("aaAbcBC"), 3);
}

TEST(NumberOfSpecialChars, LeetCodeExample2_ReturnsZero) {
    EXPECT_EQ(numberOfSpecialChars("abc"), 0);
}

TEST(NumberOfSpecialChars, LeetCodeExample3_ReturnsTwo) {
    // AbBCab -> A/a, B/b (no lowercase c)
    EXPECT_EQ(numberOfSpecialChars("AbBCab"), 2);
}

TEST(NumberOfSpecialChars, MixedCasesNoPairs_ReturnsZero) {
    EXPECT_EQ(numberOfSpecialChars("aB"), 0);
    EXPECT_EQ(numberOfSpecialChars("aBc"), 0);
}

TEST(NumberOfSpecialChars, MultiplePairs_ReturnsTwo) {
    EXPECT_EQ(numberOfSpecialChars("aAbB"), 2);
}

TEST(NumberOfSpecialChars, SameLetterBothCasesCountedOnce) {
    EXPECT_EQ(numberOfSpecialChars("aAaA"), 1);
}

TEST(NumberOfSpecialChars, OneSpecialAmongOthers_ReturnsOne) {
    EXPECT_EQ(numberOfSpecialChars("xyzX"), 1);
}
