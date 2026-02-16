#include "strings/group_anagrams.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"
#include <vector>
#include <string>

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt


TEST(GroupAnagrams,BaseCaseFromLeetCode)
{
    std::vector<std::string> words={"eat","tea","tan","ate","nat","bat"};
    std::vector<std::vector<std::string>> actual=groupAnagrams(words);
    std::vector<std::vector<std::string>> expected={{"bat"},{"nat","tan"},{"ate","eat","tea"}};
}