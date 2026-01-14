#include "hash_maps_and_sets/is_anagram.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(Anagram,BaseCase)
{
    std::string s1="bandzior";
    std::string s2="zbrodnia";
    EXPECT_TRUE(isAnagram(s1,s2));

}

TEST(Anagram,EmptyEmpty_IsTrue)
{
    std::string s1="";
    std::string s2="";
    EXPECT_TRUE(isAnagram(s1,s2));
}

TEST(Anagram,EmptyNonEmpty_IsFalse)
{
    std::string s1="";
    std::string s2="a";
    EXPECT_FALSE(isAnagram(s1,s2));
}

TEST(Anagram,SingleChar_Same_IsTrue)
{
    std::string s1="x";
    std::string s2="x";
    EXPECT_TRUE(isAnagram(s1,s2));
}

TEST(Anagram,SingleChar_Different_IsFalse)
{
    std::string s1="x";
    std::string s2="y";
    EXPECT_FALSE(isAnagram(s1,s2));
}

TEST(Anagram,SameString_IsTrue)
{
    std::string s1="algorithm";
    std::string s2="algorithm";
    EXPECT_TRUE(isAnagram(s1,s2));
}

TEST(Anagram,LengthMismatch_IsFalse)
{
    std::string s1="abc";
    std::string s2="ab";
    EXPECT_FALSE(isAnagram(s1,s2));
}

TEST(Anagram,SimplePositive_IsTrue)
{
    std::string s1="listen";
    std::string s2="silent";
    EXPECT_TRUE(isAnagram(s1,s2));
}

TEST(Anagram,SimpleNegative_IsFalse)
{
    std::string s1="hello";
    std::string s2="bello";
    EXPECT_FALSE(isAnagram(s1,s2));
}

TEST(Anagram,DuplicateCounts_Match_IsTrue)
{
    std::string s1="aabbcc";
    std::string s2="ccbbaa";
    EXPECT_TRUE(isAnagram(s1,s2));
}

TEST(Anagram,DuplicateCounts_Mismatch_IsFalse)
{
    std::string s1="aabbc";
    std::string s2="abbbc";
    EXPECT_FALSE(isAnagram(s1,s2));
}

TEST(Anagram,AllSameChar_Positive_IsTrue)
{
    std::string s1="zzzzzz";
    std::string s2="zzzzzz";
    EXPECT_TRUE(isAnagram(s1,s2));
}

TEST(Anagram,AllSameChar_Negative_IsFalse)
{
    std::string s1="zzzzzz";
    std::string s2="zzzzzy";
    EXPECT_FALSE(isAnagram(s1,s2));
}

TEST(Anagram,CaseSensitive_ByDefaultDifferent_IsFalse)
{
    // If your intended behavior is case-insensitive, this test should be changed accordingly.
    std::string s1="Abc";
    std::string s2="bca";
    EXPECT_FALSE(isAnagram(s1,s2));
}

TEST(Anagram,WhitespaceCountsAsChar_IsFalse)
{
    // If your intended behavior is "ignore spaces", change expected to TRUE and normalize input in solution.
    std::string s1="a b";
    std::string s2="ab";
    EXPECT_FALSE(isAnagram(s1,s2));
}

TEST(Anagram,PunctuationCountsAsChar_Positive_IsTrue)
{
    // Exact multiset of characters, including punctuation
    std::string s1="a!b!c";
    std::string s2="!abc!!";
    EXPECT_FALSE(isAnagram(s1,s2)); // different counts of '!' (2 vs 3)
}

TEST(Anagram,PunctuationCountsAsChar_TrueCase_IsTrue)
{
    std::string s1="a!b!c";
    std::string s2="!abc!";
    EXPECT_TRUE(isAnagram(s1,s2));
}

TEST(Anagram,BigSample_ReversedAlphabet_IsTrue)
{
    std::string s1="abcdefghijklmnopqrstuvwxyz";
    std::string s2="zyxwvutsrqponmlkjihgfedcba";
    EXPECT_TRUE(isAnagram(s1,s2));
}

TEST(Anagram,BigSample_OneCharOff_IsFalse)
{
    std::string s1="abcdefghijklmnopqrstuvwxyz";
    std::string s2="zyxwvutsrqponmlkjihgfedcbax"; // 'a' replaced by 'x' => counts differ
    EXPECT_FALSE(isAnagram(s1,s2));
}

TEST(Anagram,ManyDuplicates_Medium_IsTrue)
{
    std::string s1="aaaabbbbccccddddeeeeffff";
    std::string s2="ffffeeeebbbbddddaaaacccc";
    EXPECT_TRUE(isAnagram(s1,s2));
}

TEST(Anagram,ManyDuplicates_Medium_IsFalse)
{
    std::string s1="aaaabbbbccccddddeeeeffff";
    std::string s2="ffffeeeebbbbddddaaaacccx"; // one char changed
    EXPECT_FALSE(isAnagram(s1,s2));
}