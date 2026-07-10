#include "stack/reverse_polish_notation.hpp"
#include <gtest/gtest.h>

TEST(ReversePolishNotation, SingleNumber) {
    EXPECT_EQ(reversePolishNotation({"42"}), 42);
}

TEST(ReversePolishNotation, SimpleAddition) {
    EXPECT_EQ(reversePolishNotation({"3", "4", "+"}), 7);
}

TEST(ReversePolishNotation, SimpleSubtraction) {
    EXPECT_EQ(reversePolishNotation({"10", "3", "-"}), 7);
}

TEST(ReversePolishNotation, SimpleMultiplication) {
    EXPECT_EQ(reversePolishNotation({"2", "3", "*"}), 6);
}

TEST(ReversePolishNotation, SimpleDivision) {
    EXPECT_EQ(reversePolishNotation({"20", "4", "/"}), 5);
}

TEST(ReversePolishNotation, ClassicExample) {
    EXPECT_EQ(reversePolishNotation({"2", "1", "+", "3", "*"}), 9);
}

TEST(ReversePolishNotation, DiscussedExample) {
    EXPECT_EQ(reversePolishNotation({"50", "3", "17", "+", "2", "-", "/"}), 2);
}

TEST(ReversePolishNotation, ChainedOperations) {
    EXPECT_EQ(reversePolishNotation({"4", "13", "5", "/", "+"}), 6);
}
