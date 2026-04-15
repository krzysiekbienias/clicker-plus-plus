#include "hash_maps_and_sets/minimum_removals_for_distinct_charcter_frequencies.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

TEST(MinDeletionsTest, AlreadyGood) {
    std::string s = "aab";
    int expected = 0;
    int actual = minDeletionsForDistinctCharactersFreq(s);
    EXPECT_EQ(actual, expected);
}

// Test Case 2: Simple overlap requiring minimal deletions
TEST(MinDeletionsTest, SimpleOverlap) {
    // aaabbbcc -> a:3, b:3, c:2. One 'b' must go.
    std::string s = "aaabbbcc";
    int expected = 2;
    int actual = minDeletionsForDistinctCharactersFreq(s);
    EXPECT_EQ(actual, expected);
}

// Test Case 3: Complex overlapping frequencies (The Example Case)
TEST(MinDeletionsTest, ComplexOverlap) {
    // ceabaacb -> a:3, b:2, c:2, e:1.
    // 'c' or 'b' must drop to a frequency not taken.
    std::string s = "ceabaacb";
    int expected = 2;
    int actual = minDeletionsForDistinctCharactersFreq(s);
    EXPECT_EQ(actual, expected);
}

// Test Case 4: Multiple characters needing to be deleted entirely
TEST(MinDeletionsTest, CascadeToZero) {
    // All characters appear once: a:1, b:1, c:1
    // 1st char stays at 1, 2nd char moves to 0, 3rd char moves to 0.
    std::string s = "abc";
    int expected = 2;
    int actual = minDeletionsForDistinctCharactersFreq(s);
    EXPECT_EQ(actual, expected);
}

// Test Case 5: Large frequency collision
TEST(MinDeletionsTest, LargeFrequencyCollision) {
    // aaaaa bbbbb ccccc (5, 5, 5)
    // Needs to become (5, 4, 3) -> deletions: 1 + 2 = 3
    std::string s = "aaaaabbbbbccccc";
    int expected = 3;
    int actual = minDeletionsForDistinctCharactersFreq(s);
    EXPECT_EQ(actual, expected);
}

// Test Case 6: Empty String
TEST(MinDeletionsTest, EmptyString) {
    std::string s = "";
    int expected = 0;
    int actual = minDeletionsForDistinctCharactersFreq(s);
    EXPECT_EQ(actual, expected);
}

// Test Case 7: Single Character
TEST(MinDeletionsTest, SingleCharacter) {
    std::string s = "vvvvv";
    int expected = 0;
    int actual = minDeletionsForDistinctCharactersFreq(s);
    EXPECT_EQ(actual, expected);
}