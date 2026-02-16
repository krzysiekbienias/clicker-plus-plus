#include "two_pointers/save_boat.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt


TEST(RescueBoats,TrivalCase)
{
    EXPECT_EQ(rescueBoats({1,2},3),1);
    EXPECT_EQ(rescueBoats({3,5,3,4},5),4);
    EXPECT_EQ(rescueBoats({3,2,2,1},3),3);
}