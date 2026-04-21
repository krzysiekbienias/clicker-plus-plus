#include <gtest/gtest.h>
#include <strings/palindrome_check.hpp>

// Test a standard lowercase palindrome
TEST(IsPalindromeSentenceTest, BasicPalindrome) {
    std::string input = "racecar";
    EXPECT_TRUE(isPalindromeSentence(input));
}

// Test with mixed casing and spaces
TEST(IsPalindromeSentenceTest, MixedCaseAndSpaces) {
    std::string input = "A man a plan a canal Panama";
    EXPECT_TRUE(isPalindromeSentence(input));
}

// Test with complex punctuation and non-alphanumeric characters
TEST(IsPalindromeSentenceTest, ComplexPunctuation) {
    std::string input = "Was it a car or a cat I saw?";
    EXPECT_TRUE(isPalindromeSentence(input));
}

// Test a string that is clearly not a palindrome
TEST(IsPalindromeSentenceTest, NotAPalindrome) {
    std::string input = "Hello World";
    EXPECT_FALSE(isPalindromeSentence(input));
}

// Test with numbers included in the sentence
TEST(IsPalindromeSentenceTest, AlphanumericPalindrome) {
    std::string input = "0P0";
    EXPECT_TRUE(isPalindromeSentence(input));

    std::string input2 = "12321";
    EXPECT_TRUE(isPalindromeSentence(input2));
}

// Test edge case: Empty string (usually considered a palindrome)
TEST(IsPalindromeSentenceTest, EmptyString) {
    std::string input = "";
    EXPECT_TRUE(isPalindromeSentence(input));
}

// Test edge case: Single character
TEST(IsPalindromeSentenceTest, SingleCharacter) {
    std::string input = "a";
    EXPECT_TRUE(isPalindromeSentence(input));
}

// Test edge case: Only non-alphanumeric characters
TEST(IsPalindromeSentenceTest, OnlyPunctuation) {
    std::string input = "!!! ??? ";
    EXPECT_TRUE(isPalindromeSentence(input));
}

// Test case-sensitive mismatch
TEST(IsPalindromeSentenceTest, NearMissPalindrome) {
    std::string input = "race a car";
    // 'e' vs 'a' mismatch
    EXPECT_FALSE(isPalindromeSentence(input));
}