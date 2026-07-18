#include "two_pointers/remove_vowels.hpp"
#include <gtest/gtest.h>

#include <string>
#include <tuple>

// Ten sam zestaw probek testowany na obu implementacjach:
//  - removeVowels               (two-pointer, in-place)
//  - removeVowelsBuildFromEmpty (buduje nowy string)

struct RemoveVowelsCase {
    std::string input;
    std::string expected;
};

class RemoveVowelsBothVersions
    : public ::testing::TestWithParam<RemoveVowelsCase> {};

TEST_P(RemoveVowelsBothVersions, TwoPointerInPlace) {
    const RemoveVowelsCase& c = GetParam();
    std::string s = c.input;  // lvalue: funkcja bierze std::string&
    EXPECT_EQ(removeVowels(s), c.expected);
}

TEST_P(RemoveVowelsBothVersions, BuildFromEmpty) {
    const RemoveVowelsCase& c = GetParam();
    EXPECT_EQ(removeVowelsBuildFromEmpty(c.input), c.expected);
}

INSTANTIATE_TEST_SUITE_P(
    RemoveVowelsSamples,
    RemoveVowelsBothVersions,
    ::testing::Values(
        RemoveVowelsCase{"leetcodeisacommunityforcoders", "ltcdscmmntyfrcdrs"},
        RemoveVowelsCase{"", ""},
        RemoveVowelsCase{"aeiou", ""},
        RemoveVowelsCase{"bcdfg", "bcdfg"},
        RemoveVowelsCase{"a", ""},
        RemoveVowelsCase{"b", "b"},
        RemoveVowelsCase{"banana", "bnn"},
        RemoveVowelsCase{"aaaa", ""},
        RemoveVowelsCase{"aabbaa", "bb"},
        RemoveVowelsCase{"programming", "prgrmmng"},
        RemoveVowelsCase{"rhythm", "rhythm"}));
