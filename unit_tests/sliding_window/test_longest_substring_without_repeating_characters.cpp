#include <gtest/gtest.h>
#include <vector>
#include <sliding_window/longest_substring_without_repeating_characters.hpp>


// ---------------------------
// Suite 1: length-returning
// ---------------------------
TEST(LongestSubstringWithoutRepeats_Length, BasicCases) {
    EXPECT_EQ(longestStringWithoutRepeatingCharacters("abcba"), 3);   // "abc" or "cba"
    EXPECT_EQ(longestStringWithoutRepeatingCharacters("bbbbb"), 1);   // "b"
    EXPECT_EQ(longestStringWithoutRepeatingCharacters(""), 0);
}

TEST(LongestSubstringWithoutRepeats_Length, ClassicExample) {
    EXPECT_EQ(longestStringWithoutRepeatingCharacters("pwwkew"), 3);  // "wke" or "kew"
    EXPECT_EQ(longestStringWithoutRepeatingCharacters("dvdf"), 3);    // "vdf"
}


// ---------------------------
// Suite 2: substring-returning
// ---------------------------
// NOTE: These expectations assume the common policy: update best only when (len > bestLen),
// so ties keep the FIRST best substring encountered.
TEST(LongestSubstringWithoutRepeats_Substring, BasicCases) {
    EXPECT_EQ(longestStringWithoutRepeatingCharactersExplicite("abcba"), "abc"); // first max encountered
    EXPECT_EQ(longestStringWithoutRepeatingCharactersExplicite("bbbbb"), "b");
    EXPECT_EQ(longestStringWithoutRepeatingCharactersExplicite(""), "");
}

TEST(LongestSubstringWithoutRepeats_Substring, ClassicExample) {
    EXPECT_EQ(longestStringWithoutRepeatingCharactersExplicite("pwwkew"), "wke"); // tie with "kew", first kept
    EXPECT_EQ(longestStringWithoutRepeatingCharactersExplicite("dvdf"), "vdf");
}

