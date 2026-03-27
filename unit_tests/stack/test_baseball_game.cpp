#include "stack/baseball_game.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt


TEST(BaseballGame,TrivalCalse)
{
    int actual=calPoints({"5","-2","4","C","D","9","+","+"});
    EXPECT_EQ(actual,27);

}

TEST(BaseballGame, BasicExample) {
    int actual = calPoints({"5", "2", "C", "D", "+"});
    EXPECT_EQ(actual, 30);
}

TEST(BaseballGame, OnlyNumericScores) {
    int actual = calPoints({"1", "2", "3", "4"});
    EXPECT_EQ(actual, 10);
}

TEST(BaseballGame, CancelLastScore) {
    int actual = calPoints({"7", "3", "C"});
    EXPECT_EQ(actual, 7);
}

TEST(BaseballGame, DoublePreviousScore) {
    int actual = calPoints({"5", "D"});
    EXPECT_EQ(actual, 15); // 5 + 10
}

TEST(BaseballGame, SumPreviousTwoScores) {
    int actual = calPoints({"5", "2", "+"});
    EXPECT_EQ(actual, 14); // 5 + 2 + 7
}

TEST(BaseballGame, NegativeNumbersAreHandledCorrectly) {
    int actual = calPoints({"-5", "-2", "+"});
    EXPECT_EQ(actual, -14); // -5 + -2 + -7
}

TEST(BaseballGame, MultipleCancelsAndAdds) {
    int actual = calPoints({"10", "20", "C", "D", "+"});
    EXPECT_EQ(actual, 60); // 10, 20 -> C removes 20, D => 20, + => 30
}

TEST(BaseballGame, ChainOfDoubleOperations) {
    int actual = calPoints({"3", "D", "D"});
    EXPECT_EQ(actual, 21); // 3 + 6 + 12
}

TEST(BaseballGame, PlusUsesLastTwoValidScores) {
    int actual = calPoints({"1", "2", "3", "+"});
    EXPECT_EQ(actual, 11); // 1 + 2 + 3 + 5
}

TEST(BaseballGame, ComplexMixedOperations) {
    int actual = calPoints({"8", "-3", "D", "+", "C", "5"});
    EXPECT_EQ(actual, 4); // 8, -3, -6, -9, C removes -9, then +5 => total 4? let's compute carefully
}