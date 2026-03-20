#include <gtest/gtest.h>

#include "dynamic_programming/min_cost_for_tickets.hpp"

TEST(MinimumCostTicketsTest, SingleTravelDay) {
    std::vector<int> trainDays = {1};
    std::vector<int> costs = {2, 7, 15};

    EXPECT_EQ(minimumCostTickets(trainDays, costs), 2);
}

TEST(MinimumCostTicketsTest, ExampleCaseWithDay30And31) {
    std::vector<int> trainDays = {1,2,3,4,5,6,7,8,9,10,30,31};
    std::vector<int> costs = {2, 7, 15};

    EXPECT_EQ(minimumCostTickets(trainDays, costs), 17);
}

TEST(MinimumCostTicketsTest, MixedSparseAndDenseTravelDays) {
    std::vector<int> trainDays = {1,2,3,5,7,8,12,13,20,21,22,23,24,30};
    std::vector<int> costs = {3, 10, 25};

    EXPECT_EQ(minimumCostTickets(trainDays, costs), 25);
}

TEST(MinimumCostTicketsTest, ClassicLeetCodeStyleCase) {
    std::vector<int> trainDays = {1,4,6,7,8,20};
    std::vector<int> costs = {2, 7, 15};

    EXPECT_EQ(minimumCostTickets(trainDays, costs), 11);
}

TEST(MinimumCostTicketsTest, LastDayOfYearOnly) {
    std::vector<int> trainDays = {365};
    std::vector<int> costs = {2, 7, 15};

    EXPECT_EQ(minimumCostTickets(trainDays, costs), 2);
}