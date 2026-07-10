#include "math_and_geometry/is_palindrome_number.hpp"
#include <gtest/gtest.h>

TEST(IsPalindromeNumber, SingleDigitNumbersArePalindromes) {
    EXPECT_TRUE(isPalindrome(0));
    EXPECT_TRUE(isPalindrome(5));
    EXPECT_TRUE(isPalindrome(9));
}

TEST(IsPalindromeNumber, NegativeNumbersAreNotPalindromes) {
    EXPECT_FALSE(isPalindrome(-1));
    EXPECT_FALSE(isPalindrome(-121));
}

TEST(IsPalindromeNumber, NumbersEndingWithZeroAreNotPalindromes) {
    EXPECT_FALSE(isPalindrome(10));
    EXPECT_FALSE(isPalindrome(100));
    EXPECT_FALSE(isPalindrome(1230));
}

TEST(IsPalindromeNumber, EvenLengthPalindromes) {
    EXPECT_TRUE(isPalindrome(11));
    EXPECT_TRUE(isPalindrome(1221));
    EXPECT_TRUE(isPalindrome(123321));
}

TEST(IsPalindromeNumber, OddLengthPalindromes) {
    EXPECT_TRUE(isPalindrome(121));
    EXPECT_TRUE(isPalindrome(12321));
    EXPECT_TRUE(isPalindrome(1234321));
}

TEST(IsPalindromeNumber, NonPalindromes) {
    EXPECT_FALSE(isPalindrome(12));
    EXPECT_FALSE(isPalindrome(123));
    EXPECT_FALSE(isPalindrome(1231));
    EXPECT_FALSE(isPalindrome(123421));
}
