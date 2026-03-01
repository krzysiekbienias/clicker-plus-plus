#include "dynamic_programming/best_time_to_buy_and_sell.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt



TEST(MaxProfitSingleTransaction, EmptyVector_ReturnsZero) {
    std::vector<int> prices{};
    EXPECT_EQ(maxProfitSingleTransaction(prices), 0);
}

TEST(MaxProfitSingleTransaction, SingleElement_ReturnsZero) {
    std::vector<int> prices{7};
    EXPECT_EQ(maxProfitSingleTransaction(prices), 0);
}

TEST(MaxProfitSingleTransaction, TwoElements_Increasing) {
    std::vector<int> prices{1, 5};
    EXPECT_EQ(maxProfitSingleTransaction(prices), 4);
}

TEST(MaxProfitSingleTransaction, TwoElements_Decreasing) {
    std::vector<int> prices{5, 1};
    EXPECT_EQ(maxProfitSingleTransaction(prices), 0);
}

TEST(MaxProfitSingleTransaction, StrictlyIncreasing_ReturnsLastMinusFirst) {
    std::vector<int> prices{1, 2, 3, 4, 5};
    EXPECT_EQ(maxProfitSingleTransaction(prices), 4);
}

TEST(MaxProfitSingleTransaction, StrictlyDecreasing_ReturnsZero) {
    std::vector<int> prices{9, 7, 4, 3, 1};
    EXPECT_EQ(maxProfitSingleTransaction(prices), 0);
}

TEST(MaxProfitSingleTransaction, ClassicExample_ReturnsFive) {
    // buy at 1, sell at 6 => profit = 5
    std::vector<int> prices{7, 1, 5, 3, 6, 4};
    EXPECT_EQ(maxProfitSingleTransaction(prices), 5);
}

TEST(MaxProfitSingleTransaction, AnotherClassicExample_ReturnsZero) {
    std::vector<int> prices{7, 6, 4, 3, 1};
    EXPECT_EQ(maxProfitSingleTransaction(prices), 0);
}

TEST(MaxProfitSingleTransaction, FlatPrices_ReturnsZero) {
    std::vector<int> prices{3, 3, 3, 3};
    EXPECT_EQ(maxProfitSingleTransaction(prices), 0);
}

TEST(MaxProfitSingleTransaction, DuplicatesWithDipAndRise) {
    // best: buy at 1, sell at 5 => 4
    std::vector<int> prices{2, 2, 1, 1, 5, 5};
    EXPECT_EQ(maxProfitSingleTransaction(prices), 4);
}

TEST(MaxProfitSingleTransaction, EarlyHighThenLowerBuyLater) {
    // best: buy at 1 (day 3), sell at 6 (day 5) => 5
    std::vector<int> prices{5, 4, 1, 2, 6};
    EXPECT_EQ(maxProfitSingleTransaction(prices), 5);
}

TEST(MaxProfitSingleTransaction, ProfitComesFromLaterSegmentNotFirstRise) {
    // possible profits:
    // buy 2 sell 4 => 2
    // buy 1 sell 7 => 6 (best)
    std::vector<int> prices{2, 4, 1, 7};
    EXPECT_EQ(maxProfitSingleTransaction(prices), 6);
}