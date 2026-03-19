#include "greedy/balanced_two_flights_city.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

TEST(TwoCitySchedCostTest, HandlesSmallestCase) {
    std::vector<std::vector<int>> costs = {
        {1, 2},
        {3, 4}
    };

    EXPECT_EQ(balancedTwoCityFlight(costs), 5);
}

TEST(TwoCitySchedCostTest, HandlesClassicExample) {
    std::vector<std::vector<int>> costs = {
        {10, 20},
        {30, 200},
        {400, 50},
        {30, 20}
    };

    EXPECT_EQ(balancedTwoCityFlight(costs), 110);
}

TEST(TwoCitySchedCostTest, HandlesAllEqualCosts) {
    std::vector<std::vector<int>> costs = {
        {100, 100},
        {100, 100},
        {100, 100},
        {100, 100}
    };

    EXPECT_EQ(balancedTwoCityFlight(costs), 400);
}

TEST(TwoCitySchedCostTest, HandlesMixedPreferences) {
    std::vector<std::vector<int>> costs = {
        {100, 200},
        {300, 150},
        {400, 50},
        {200, 300}
    };

    EXPECT_EQ(balancedTwoCityFlight(costs), 500);
}

TEST(TwoCitySchedCostTest, HandlesSixPeopleCase) {
    std::vector<std::vector<int>> costs = {
        {259, 770},
        {448, 54},
        {926, 667},
        {184, 139},
        {840, 118},
        {577, 469}
    };

    EXPECT_EQ(balancedTwoCityFlight(costs), 1859);
}

TEST(TwoCitySchedCostTest, HandlesEightPeopleCase) {
    std::vector<std::vector<int>> costs = {
        {515, 563},
        {451, 713},
        {537, 709},
        {343, 819},
        {855, 779},
        {457, 60},
        {650, 359},
        {631, 42}
    };

    EXPECT_EQ(balancedTwoCityFlight(costs), 3086);
}