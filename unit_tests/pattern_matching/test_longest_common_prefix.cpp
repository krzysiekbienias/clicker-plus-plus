#include "pattern_matching/longest_common_prefix.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"
#include <string>
// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

TEST(LongestCommonPrefix,TrivalCase)
{
    std::vector<std::string> inp={"flower","flow","flight"};
    std::vector<std::string> inp2={"dog","racecar","car"};
    std::string expected1="fl";
    std::string expected2="";
    EXPECT_EQ(longestCommonPrefix(inp),expected1);
    EXPECT_EQ(longestCommonPrefix(inp2),expected2);
}

TEST(LongestCommonPrefix,Failing)
{
    std::vector<std::string> inp={"ab","a"};

    EXPECT_EQ(longestCommonPrefix(inp),"a");
}


TEST(LongestCommonPrefix,Failing2)
{
    std::vector<std::string> inp={"a","a","b"};

    EXPECT_EQ(longestCommonPrefix(inp),"");
}


TEST(LongestCommonPrefix,Degenerated)
{
    std::vector<std::string> inp={"a"};


    EXPECT_EQ(longestCommonPrefix(inp),"a");

}


