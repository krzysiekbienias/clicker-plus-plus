#include "greedy/rearrangement_for_minimal_signed_value.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

TEST(RearrangementForMinimalSignedValue,PositiveNumber)
{
    long long actual=rearrangementForMinimalSignedValue(310);
    EXPECT_EQ(actual,103);
}

TEST(RearrangementForMinimalSignedValue,NegativeNumber)
{
    long long actual=rearrangementForMinimalSignedValue(-7605);
    EXPECT_EQ(actual,-7650);
}