#include "strings/injecting_spaces_into_string.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

TEST(SpaceInjection, ClassicCase)
{
    std::string s = "EnjoyYourCoffee";
    std::string expected = "Enjoy Your Coffee";
    std::vector<int> spaces={5,9};
    std::string actual=addSpaces(s,spaces);
    EXPECT_EQ(actual,expected);
}

TEST(SpaceInjection, ClassicCase2)
{
    std::string s = "icodeinpython";
    std::string expected = "i code in py thon";
    std::vector<int> spaces={1,5,7,9};
    std::string actual=addSpaces(s,spaces);
    EXPECT_EQ(actual,expected);
}