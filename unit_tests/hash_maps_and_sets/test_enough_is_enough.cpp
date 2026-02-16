#include "hash_maps_and_sets/enough_is_enough.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

using ::testing::ElementsAre;

TEST(EnoughIsEnough,FromCodeWars1)
{
    std::vector<int> expected={20, 37, 21};
    std::vector<int> input={20,37,20,21};
    std::vector<int> actual=enoughIsEnough(input,1);
    EXPECT_THAT(actual,expected);
}

TEST(EnoughIsEnough,FromCodeWars2)
{
    std::vector<int> expected={1, 1, 3, 3, 7, 2, 2, 2};
    std::vector<int> input={1, 1, 3, 3, 7, 2, 2, 2};
    std::vector<int> actual=enoughIsEnough(input,3);
    EXPECT_THAT(actual,expected);
}