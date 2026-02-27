#include "numbers_theory/multiplies_3_or_5.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

TEST(Multiple3Or5,Simple)
{
    EXPECT_EQ(multiples3Or5(10),23);

}