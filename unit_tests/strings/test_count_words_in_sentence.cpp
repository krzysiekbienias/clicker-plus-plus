#include "strings/count_words_in_sentence.hpp"
#include <gtest/gtest.h>

#include <string>
#include <tuple>

// Liczy słowa rozdzielone jedną lub wieloma spacjami.
// Słowo = niepusty ciąg znaków innych niż spacja.

struct CountWordsCase {
    std::string input;
    int expected;
};

class CountWordsTest : public ::testing::TestWithParam<CountWordsCase> {};

TEST_P(CountWordsTest, CountsWordsSeparatedBySpaces) {
    const CountWordsCase& c = GetParam();
    EXPECT_EQ(countWords(c.input), c.expected);
}

INSTANTIATE_TEST_SUITE_P(
    CountWordsSamples,
    CountWordsTest,
    ::testing::Values(
        CountWordsCase{"", 0},
        CountWordsCase{" ", 0},
        CountWordsCase{"   ", 0},
        CountWordsCase{"a", 1},
        CountWordsCase{"hello", 1},
        CountWordsCase{"hello world", 2},
        CountWordsCase{"  hello", 1},
        CountWordsCase{"hello  ", 1},
        CountWordsCase{"  hello  ", 1},
        CountWordsCase{"hello   world", 2},
        CountWordsCase{"  a  b  c  ", 3},
        CountWordsCase{"one two three four", 4},
        CountWordsCase{"  leading and trailing  ", 3},
        CountWordsCase{"x", 1},
        CountWordsCase{"a b", 2}));
