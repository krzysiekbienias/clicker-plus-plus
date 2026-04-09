#include "hash_maps_and_sets/colorful_numbers.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"


// Basic case where the number is colorful (all sub-sequence products are unique)
// Digits: 3, 2, 4, 5 -> Products: 3, 2, 4, 5, 6, 8, 20, 24, 40, 120 (All unique)
TEST(ColorfulNumberTest, BasicColorful)
{
    int actual = colorfulNumber(3245);
    EXPECT_EQ(actual, 1);
}

// Basic case where the number is not colorful
// Digits: 3, 2, 6 -> Products include 3*2=6, and the digit 6 itself is a duplicate.
TEST(ColorfulNumberTest, BasicNotColorful)
{
    int actual = colorfulNumber(326);
    EXPECT_EQ(actual, 0);
}

// A single digit number should always be colorful
TEST(ColorfulNumberTest, SingleDigit)
{
    int actual = colorfulNumber(7);
    EXPECT_EQ(actual, 1);
}

// Numbers with duplicate digits inherently have duplicate products
TEST(ColorfulNumberTest, DuplicateDigits)
{
    EXPECT_EQ(colorfulNumber(11), 0);
    EXPECT_EQ(colorfulNumber(998), 0);
}

// Numbers containing multiple zeros will quickly generate duplicate 0 products
TEST(ColorfulNumberTest, ContainsZero)
{
    EXPECT_EQ(colorfulNumber(1020), 0);
}

// Edge case testing the bounds of the `while (num > 0)` loop
// Zero and negative numbers bypass the loop and return 1 based on current implementation
TEST(ColorfulNumberTest, EdgeCasesZeroAndNegative)
{
    EXPECT_EQ(colorfulNumber(0), 1);
    EXPECT_EQ(colorfulNumber(-25), 1);
}
