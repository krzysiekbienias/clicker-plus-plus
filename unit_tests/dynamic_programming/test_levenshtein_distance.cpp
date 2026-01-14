#include "dynamic_programming/levenshtein_distance.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(LevenshteinDistance,TwoEmptyStrings)
{
    std::string source="";
    std::string target="";
    EXPECT_EQ(levenshteinDistance(source,target),0);
}

TEST(LevenshteinDistance,EmptySource)
{
    std::string source="";
    std::string target="lala";
    EXPECT_EQ(levenshteinDistance(source,target),4);
}

TEST(LevenshteinDistance,EmptyTarget)
{
    std::string source="tenis";
    std::string target="";
    EXPECT_EQ(levenshteinDistance(source,target),5);
}

TEST(LevenshteinDistance,Basic)
{
    std::string source="abc";
    std::string target="yabd";
    EXPECT_EQ(levenshteinDistance(source,target),2);
}
