#include "simulations/sequential_digits.hpp"

#include <gtest/gtest.h>
#include <vector>

TEST(SequentialDigits, LeetCodeExample_SmallRange)
{
    EXPECT_EQ(sequentialDigits(10, 100),
              (std::vector<int>{12, 23, 34, 45, 56, 67, 78, 89}));
}

TEST(SequentialDigits, LeetCodeExample_ThreeDigitBlock)
{
    EXPECT_EQ(sequentialDigits(100, 300), (std::vector<int>{123, 234}));
}

TEST(SequentialDigits, LeetCodeExample_LargeRange)
{
    EXPECT_EQ(sequentialDigits(1000, 13000),
              (std::vector<int>{1234, 2345, 3456, 4567, 5678, 6789, 12345}));
}

TEST(SequentialDigits, NoMatchInRange)
{
    EXPECT_EQ(sequentialDigits(10, 11), std::vector<int>{});
}

TEST(SequentialDigits, SingleExactMatch)
{
    EXPECT_EQ(sequentialDigits(12, 12), (std::vector<int>{12}));
}

TEST(SequentialDigits, BelowMinimumLength_NoSingleDigits)
{
    EXPECT_EQ(sequentialDigits(1, 9), std::vector<int>{});
}

TEST(SequentialDigits, LongestSequentialNumber)
{
    EXPECT_EQ(sequentialDigits(123456789, 123456789),
              (std::vector<int>{123456789}));
}
