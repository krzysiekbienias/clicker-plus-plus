#include "strings/semordnilap.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

using namespace std;

// Helper function to sort internal pairs and the outer vector to ensure
// test reliability regardless of return order.
void sortSemordnilapResults(vector<vector<string>>& res) {
    for (auto& pair : res) {
        sort(pair.begin(), pair.end());
    }
    sort(res.begin(), res.end());
}

TEST(SemordnilapTest, BasicCase) {
    vector<string> input = {"desserts", "stressed", "hello"};
    vector<vector<string>> expected = {{"desserts", "stressed"}};

    vector<vector<string>> actual = semordnilap(input);

    sortSemordnilapResults(actual);
    sortSemordnilapResults(expected);
    EXPECT_EQ(actual, expected);
}

TEST(SemordnilapTest, MultiplePairs) {
    vector<string> input = {"dog", "god", "amigo", "palindromes", "semi", "imes", "ogimA"};
    // Note: "amigo" and "ogimA" only match if case sensitivity isn't handled.
    // Based on the provided code, it is case-sensitive.
    vector<vector<string>> expected = {{"dog", "god"}, {"semi", "imes"}};

    vector<vector<string>> actual = semordnilap(input);

    sortSemordnilapResults(actual);
    sortSemordnilapResults(expected);
    EXPECT_EQ(actual, expected);
}

TEST(SemordnilapTest, NoPairs) {
    vector<string> input = {"abcdefgh", "hello", "world", "test"};
    vector<vector<string>> expected = {};

    vector<vector<string>> actual = semordnilap(input);
    EXPECT_EQ(actual, expected);
}

TEST(SemordnilapTest, EmptyInput) {
    vector<string> input = {};
    vector<vector<string>> expected = {};

    vector<vector<string>> actual = semordnilap(input);
    EXPECT_EQ(actual, expected);
}

TEST(SemordnilapTest, PalindromeWords) {
    // A single palindrome like "racecar" should not pair with itself
    // because the problem specifies different strings/unique strings.
    // The current logic handles this correctly because 'seen.count'
    // is checked before 'seen.insert'.
    vector<string> input = {"racecar", "level", "noon"};
    vector<vector<string>> expected = {};

    vector<vector<string>> actual = semordnilap(input);
    EXPECT_EQ(actual, expected);
}

TEST(SemordnilapTest, SingleWord) {
    vector<string> input = {"abc"};
    vector<vector<string>> expected = {};

    vector<vector<string>> actual = semordnilap(input);
    EXPECT_EQ(actual, expected);
}