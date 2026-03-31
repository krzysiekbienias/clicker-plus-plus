#include "greedy/price_roundig_with_minimal_error.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

TEST(RoundingWithMinimalError,BaseCase)
{
    std::string actual=roundingWithMinimalError({"0.700","2.800","4.900"},8);
}