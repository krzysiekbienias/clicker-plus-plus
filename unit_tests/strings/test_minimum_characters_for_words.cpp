#include "strings/minimum_characters_for_words.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"


TEST(MinimumCharactersForWords,BaseCase)
{
    std::vector<char> actual=minimumCharactersForWords({"this", "that", "did", "deed", "them!", "a"});
    std::vector<char> expected={'t', 't', 'h', 'i', 's', 'a', 'd', 'd', 'e', 'e', 'm', '!'};

    EXPECT_EQ(actual,expected);

}