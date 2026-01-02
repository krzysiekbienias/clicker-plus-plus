#include <gtest/gtest.h>
#include <string>
#include <vector>
using namespace std;

// Function under test (provide your implementation elsewhere):
// string reverseWords(string A);

TEST(ReverseWords, SingleWord_NoSpaces) {
    EXPECT_EQ(reverseWords("hello"), "hello");
    EXPECT_EQ(reverseWords("a"), "a");
}

TEST(ReverseWords, TwoWords_SingleSpace) {
    EXPECT_EQ(reverseWords("hello world"), "world hello");
    EXPECT_EQ(reverseWords("a b"), "b a");
}

TEST(ReverseWords, LeadingSpaces_AreRemoved) {
    EXPECT_EQ(reverseWords("   hello world"), "world hello");
    EXPECT_EQ(reverseWords("    hello"), "hello");
}

TEST(ReverseWords, TrailingSpaces_AreRemoved) {
    EXPECT_EQ(reverseWords("hello world   "), "world hello");
    EXPECT_EQ(reverseWords("hello    "), "hello");
}

TEST(ReverseWords, MultipleSpaces_BetweenWords_CollapsedToSingle) {
    EXPECT_EQ(reverseWords("hello    world"), "world hello");
    EXPECT_EQ(reverseWords("a   b    c"), "c b a");
    EXPECT_EQ(reverseWords("one  two   three    four"), "four three two one");
}

TEST(ReverseWords, LeadingAndTrailingAndMultipleInternalSpaces) {
    EXPECT_EQ(reverseWords("   hello    world   "), "world hello");
    EXPECT_EQ(reverseWords("   a   b   c   "), "c b a");
}

TEST(ReverseWords, AllSpaces_ResultIsEmpty) {
    EXPECT_EQ(reverseWords(" "), "");
    EXPECT_EQ(reverseWords("     "), "");
    EXPECT_EQ(reverseWords("               "), "");
}

TEST(ReverseWords, EmptyString_ResultIsEmpty) {
    EXPECT_EQ(reverseWords(""), "");
}

TEST(ReverseWords, WordsWithPunctuation_AreNotSplit) {
    EXPECT_EQ(reverseWords("hi, world!"), "world! hi,");
    EXPECT_EQ(reverseWords("a...  b?? c!"), "c! b?? a...");
}

TEST(ReverseWords, MixedWhitespaceCharacters_TreatedAsNonSpaceUnlessSpecified) {
    // The statement says "space" explicitly.
    // If your solution treats ONLY ' ' as separator, tabs/newlines stay inside words.
    // If you treat any isspace() as separator, then expected output would differ.
    // Keep these tests to clarify your chosen interpretation.

    // Option A (ONLY ' ' is a separator):
    EXPECT_EQ(reverseWords("a\tb c"), "c a\tb");
    EXPECT_EQ(reverseWords("x\ny z"), "z x\ny");

    // If you decide to treat all whitespace as separators, switch to:
    // EXPECT_EQ(reverseWords("a\tb c"), "c b a");
    // EXPECT_EQ(reverseWords("x\ny z"), "z y x");
}

TEST(ReverseWords, PreservesCaseAndSymbolsInsideWords) {
    EXPECT_EQ(reverseWords("AbC dEf"), "dEf AbC");
    EXPECT_EQ(reverseWords("C++   is   fun!!"), "fun!! is C++");
}

TEST(ReverseWords, Stress_LongInput_ManyWords) {
    // Build: "w0  w1   w2    ... w999" with varying spaces
    string s;
    for (int i = 0; i < 1000; ++i) {
        s += "w" + to_string(i);
        s += string((i % 5) + 1, ' '); // 1..5 spaces
    }
    // Add leading + trailing spaces
    s = "   " + s + "    ";

    // Expected: "w999 w998 ... w0"
    string expected;
    for (int i = 999; i >= 0; --i) {
        expected += "w" + to_string(i);
        if (i) expected += " ";
    }

    EXPECT_EQ(reverseWords(s), expected);
}

TEST(ReverseWords, IdempotenceOnNormalizedSingleWord) {
    // Once normalized and single word, output should remain same.
    EXPECT_EQ(reverseWords("   solo   "), "solo");
    EXPECT_EQ(reverseWords(reverseWords("   solo   ")), "solo");
}

TEST(ReverseWords, NormalizationIsAlwaysApplied) {
    // Output must be trimmed and internally normalized to single spaces.
    EXPECT_EQ(reverseWords("  a   "), "a");
    EXPECT_EQ(reverseWords("  a   b   "), "b a");
    EXPECT_EQ(reverseWords("  a   b   c   "), "c b a");
}
