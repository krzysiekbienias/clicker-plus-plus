#include "greedy/minimal_swaps_to_alternate_binary_sequence.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

TEST(MinSwapsTest, EmptyString) {
    EXPECT_EQ(minSwaps(""), 0);
}

TEST(MinSwapsTest, SingleZero) {
    EXPECT_EQ(minSwaps("0"), 0);
}

TEST(MinSwapsTest, SingleOne) {
    EXPECT_EQ(minSwaps("1"), 0);
}

TEST(MinSwapsTest, AlreadyAlternatingStartsWithZero) {
    EXPECT_EQ(minSwaps("0101"), 0);
    EXPECT_EQ(minSwaps("010101"), 0);
}

TEST(MinSwapsTest, AlreadyAlternatingStartsWithOne) {
    EXPECT_EQ(minSwaps("1010"), 0);
    EXPECT_EQ(minSwaps("101010"), 0);
}

TEST(MinSwapsTest, TwoCharsAlreadyValid) {
    EXPECT_EQ(minSwaps("01"), 0);
    EXPECT_EQ(minSwaps("10"), 0);
}

TEST(MinSwapsTest, TwoCharsSameDigitImpossible) {
    EXPECT_EQ(minSwaps("00"), -1);
    EXPECT_EQ(minSwaps("11"), -1);
}

TEST(MinSwapsTest, EqualCountsPickBetterPattern) {
    EXPECT_EQ(minSwaps("1100"), 1);
    EXPECT_EQ(minSwaps("0011"), 1);
}

TEST(MinSwapsTest, MoreOnesRequiresPatternStartingWithOne) {
    EXPECT_EQ(minSwaps("11100"), 1);
    EXPECT_EQ(minSwaps("11010"), 2);
}

TEST(MinSwapsTest, MoreZerosRequiresPatternStartingWithZero) {
    EXPECT_EQ(minSwaps("001"), 1);
    EXPECT_EQ(minSwaps("00011"), 1);
}

TEST(MinSwapsTest, ImpossibleWhenCountDifferenceGreaterThanOne) {
    EXPECT_EQ(minSwaps("111"), -1);
    EXPECT_EQ(minSwaps("000"), -1);
    EXPECT_EQ(minSwaps("1111"), -1);
    EXPECT_EQ(minSwaps("11110"), -1);
}

TEST(MinSwapsTest, LongerSequenceMultipleSwaps) {
    EXPECT_EQ(minSwaps("1110000"), 2);
    EXPECT_EQ(minSwaps("00110101"), 1);
}

TEST(MinSwapsTest, AllPositionsWrongButFixable) {
    EXPECT_EQ(minSwaps("1010101010"), 0);
    EXPECT_EQ(minSwaps("0101010101"), 0);
}

TEST(MinSwapsTest, ClassicExampleFromProblem) {
    EXPECT_EQ(minSwaps("001011"), 1);
}
