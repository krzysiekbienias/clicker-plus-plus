#include "stack/clear_digits.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

#include <gtest/gtest.h>
#include <string>

// declare or include your function:
// std::string clearDigits(std::string s);

TEST(ClearDigits, EmptyString) {
    EXPECT_EQ(clearDigits(""), "");
}

TEST(ClearDigits, NoDigits_ReturnsSameString) {
    EXPECT_EQ(clearDigits("abc"), "abc");
    EXPECT_EQ(clearDigits("HelloWorld"), "HelloWorld");
}

TEST(ClearDigits, OnlyDigits_ReturnsEmpty) {
    EXPECT_EQ(clearDigits("0"), "");
    EXPECT_EQ(clearDigits("123456"), "");
}

TEST(ClearDigits, LeadingDigits_DoNothing) {
    EXPECT_EQ(clearDigits("1a"), "a");     // '1' can't pop anything
    EXPECT_EQ(clearDigits("12abc"), "abc");
}

TEST(ClearDigits, SingleDigitRemovesPreviousNonDigit) {
    EXPECT_EQ(clearDigits("a1"), "");      // pop 'a'
    EXPECT_EQ(clearDigits("ab2"), "a");    // pop 'b'
    EXPECT_EQ(clearDigits("ab2c"), "ac");  // pop 'b', keep 'a' and 'c'
}

TEST(ClearDigits, MultipleDigitsCascadePops) {
    EXPECT_EQ(clearDigits("abc12"), "a");  // pop 'c' then pop 'b'
    EXPECT_EQ(clearDigits("abcd999"), "a");// pop d,c,b (3 pops)
}

TEST(ClearDigits, DigitsInMiddle) {
    EXPECT_EQ(clearDigits("a1b2c3"), "");  // a pop, b pop, c pop
    EXPECT_EQ(clearDigits("ab1c"), "ac");  // pop 'b'
    EXPECT_EQ(clearDigits("ab12c"), "c");  // pop 'b', then pop 'a'
}

TEST(ClearDigits, PopWhenEmpty_IsSafe) {
    EXPECT_EQ(clearDigits("1"), "");
    EXPECT_EQ(clearDigits("11"), "");
    EXPECT_EQ(clearDigits("1a2"), "");     // '1' no-op, keep 'a', '2' pops 'a'
}

TEST(ClearDigits, MixedComplexExample) {
    // Walkthrough:
    // a b 1 -> a
    // c d 2 -> a c
    // 3 -> a
    // e -> a e
    EXPECT_EQ(clearDigits("ab1cd23e"), "ae");
}
