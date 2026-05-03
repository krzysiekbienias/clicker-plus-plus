#include "greedy/best_time_to_buy_and_sell_II.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

TEST(MaxProfitMultipleTrans, EmptyVector_ReturnsZero) {
    std::vector<int> prices{};
    EXPECT_EQ(maxProfitMultipleTrans(prices), 0);
}

TEST(MaxProfitMultipleTrans, SingleElement_ReturnsZero) {
    std::vector<int> prices{5};
    EXPECT_EQ(maxProfitMultipleTrans(prices), 0);
}

TEST(MaxProfitMultipleTrans, TwoElements_Increasing) {
    std::vector<int> prices{1, 5};
    EXPECT_EQ(maxProfitMultipleTrans(prices), 4);
}

TEST(MaxProfitMultipleTrans, TwoElements_Decreasing_ReturnsZero) {
    std::vector<int> prices{5, 1};
    EXPECT_EQ(maxProfitMultipleTrans(prices), 0);
}

TEST(MaxProfitMultipleTrans, StrictlyIncreasing_CollectsEveryStep) {
    // (2-1) + (3-2) + (4-3) + (5-4) = 4
    std::vector<int> prices{1, 2, 3, 4, 5};
    EXPECT_EQ(maxProfitMultipleTrans(prices), 4);
}

TEST(MaxProfitMultipleTrans, StrictlyDecreasing_ReturnsZero) {
    std::vector<int> prices{9, 7, 4, 3, 1};
    EXPECT_EQ(maxProfitMultipleTrans(prices), 0);
}

TEST(MaxProfitMultipleTrans, FlatPrices_ReturnsZero) {
    std::vector<int> prices{3, 3, 3, 3};
    EXPECT_EQ(maxProfitMultipleTrans(prices), 0);
}

TEST(MaxProfitMultipleTrans, ClassicExample_ReturnsSeven) {
    // buy@1 sell@3 (+2), buy@2 sell@5 (+3) => 5
    std::vector<int> prices{1, 3, 2, 5};
    EXPECT_EQ(maxProfitMultipleTrans(prices), 5);
}

TEST(MaxProfitMultipleTrans, LeetCodeExample1_ReturnsSeven) {
    // buy@1 sell@5 (+4), buy@3 sell@6 (+3) => 7
    std::vector<int> prices{7, 1, 5, 3, 6, 4};
    EXPECT_EQ(maxProfitMultipleTrans(prices), 7);
}

TEST(MaxProfitMultipleTrans, LeetCodeExample2_ReturnsEight) {
    // (2-1)+(3-2)+(4-3)+(5-4) but with dip: buy@1,sell@2,buy@3,sell@4,buy@5 sell@6 => 4
    // prices{1,2,3,4,5} => 4; with extra: {1,2,3,4,5,6} => 5
    std::vector<int> prices{1, 2, 3, 4, 5, 6};
    EXPECT_EQ(maxProfitMultipleTrans(prices), 5);
}

TEST(MaxProfitMultipleTrans, DipInMiddle_SkipsNegativeDiff) {
    // diffs: -3, +4, -2, +6 => collect 4+6 = 10
    std::vector<int> prices{5, 2, 6, 4, 10};
    EXPECT_EQ(maxProfitMultipleTrans(prices), 10);
}