#include "strings/get_the_middle_character.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

TEST(MiddleCharacter,BaseTest)
{
   EXPECT_EQ(getMiddle("test"),"es");
   EXPECT_EQ(getMiddle("testing"),"t");
}

TEST(MiddleCharacter,ShortStrings)
{
   EXPECT_EQ(getMiddle(""),"");
   EXPECT_EQ(getMiddle("ma"),"ma");
}