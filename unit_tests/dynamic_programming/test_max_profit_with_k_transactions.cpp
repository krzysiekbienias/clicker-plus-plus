#include "dynamic_programming/max_profit_with_k_transactions.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

TEST(MaxProfitWithKTransactions,BaseCase)
{
    std::vector<int> equityPrices{5, 11, 3, 50, 60, 90};
    int nbOfTransactions=2;
    int actual=maxProfitWithKTransactions(equityPrices,nbOfTransactions);
    EXPECT_EQ(actual,93);
}
