#include "strings/bracket_key_interpreter.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

TEST(BracketKeyInterpreterTest, BasicSingleSubstitution) {
    std::string s = "(a)";
    std::vector<std::vector<std::string>> knowledge = {{"a", "aaa"}};
    std::string expected = "aaa";
    EXPECT_EQ(bracketKeyInterpreter(s, knowledge), expected);
}

TEST(BracketKeyInterpreterTest, MultipleSubstitutionsMixed) {
    std::string s = "a, (yes)(yes)(yes)(yes)aaa(yes)(yes)(yes)aaa";
    std::vector<std::vector<std::string>> knowledge = {{"yes", "yes"}};
    std::string expected = "a, yesyesyesyesaaayesyesyesaaa";
    EXPECT_EQ(bracketKeyInterpreter(s, knowledge), expected);
}

TEST(BracketKeyInterpreterTest, MultipleKeysMultipleValues) {
    std::string s = "(name) is (age) years old";
    std::vector<std::vector<std::string>> knowledge = {{"name", "bob"}, {"age", "two"}};
    std::string expected = "bob is two years old";
    EXPECT_EQ(bracketKeyInterpreter(s, knowledge), expected);
}

TEST(BracketKeyInterpreterTest, RepeatedKeyUsage) {
    std::string s = "(repeat) and (repeat)";
    std::vector<std::vector<std::string>> knowledge = {{"repeat", "again"}};
    std::string expected = "again and again";
    EXPECT_EQ(bracketKeyInterpreter(s, knowledge), expected);
}

TEST(BracketKeyInterpreterTest, UnknownKeyReturnsQuestionMark) {
    std::string s = "(unknown) keys";
    std::vector<std::vector<std::string>> knowledge = {{"known", "val"}};
    std::string expected = "? keys";
    EXPECT_EQ(bracketKeyInterpreter(s, knowledge), expected);
}

TEST(BracketKeyInterpreterTest, EmptyKnowledgeBase) {
    std::string s = "abc(def)ghi";
    std::vector<std::vector<std::string>> knowledge = {};
    std::string expected = "abc?ghi";
    EXPECT_EQ(bracketKeyInterpreter(s, knowledge), expected);
}

TEST(BracketKeyInterpreterTest, KeyMismatchedInKnowledge) {
    std::string s = "hi(name)";
    std::vector<std::vector<std::string>> knowledge = {{"a", "b"}};
    std::string expected = "hi?";
    EXPECT_EQ(bracketKeyInterpreter(s, knowledge), expected);
}

TEST(BracketKeyInterpreterTest, PlainTextNoBrackets) {
    std::string s = "plaintext";
    std::vector<std::vector<std::string>> knowledge = {{"a", "one"}};
    std::string expected = "plaintext";
    EXPECT_EQ(bracketKeyInterpreter(s, knowledge), expected);
}

TEST(BracketKeyInterpreterTest, ComplexInterleavedKeys) {
    std::string s = "x(y)z(a)";
    std::vector<std::vector<std::string>> knowledge = {{"y", "first"}, {"a", "second"}};
    std::string expected = "xfirstzsecond";
    EXPECT_EQ(bracketKeyInterpreter(s, knowledge), expected);
}