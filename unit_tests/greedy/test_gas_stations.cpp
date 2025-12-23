#include <gtest/gtest.h>
#include <vector>
#include <climits>
#include <greedy/gas_stations.hpp>

using std::vector;

// Function under test:
// int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost);

TEST(GasStation, EmptyInput) {
    vector<int> gas{};
    vector<int> cost{};
    EXPECT_EQ(canCompleteCircuit(gas, cost), -1);
}

TEST(GasStation, SingleStation_EnoughGas) {
    vector<int> gas{5};
    vector<int> cost{4};
    EXPECT_EQ(canCompleteCircuit(gas, cost), 0);
}

TEST(GasStation, SingleStation_ExactGas) {
    vector<int> gas{3};
    vector<int> cost{3};
    EXPECT_EQ(canCompleteCircuit(gas, cost), 0);
}

TEST(GasStation, SingleStation_NotEnoughGas) {
    vector<int> gas{2};
    vector<int> cost{3};
    EXPECT_EQ(canCompleteCircuit(gas, cost), -1);
}

TEST(GasStation, TotalGasLessThanTotalCost_NoSolution) {
    vector<int> gas{1, 2, 3};
    vector<int> cost{2, 2, 3};
    EXPECT_EQ(canCompleteCircuit(gas, cost), -1);
}

TEST(GasStation, BasicExample_UniqueAnswer) {
    // Classic sample: answer = 3
    vector<int> gas {1, 2, 3, 4, 5};
    vector<int> cost{3, 4, 5, 1, 2};
    EXPECT_EQ(canCompleteCircuit(gas, cost), 3);
}

TEST(GasStation, AnotherExample_UniqueAnswer) {
    // Classic sample: answer = -1
    vector<int> gas {2, 3, 4};
    vector<int> cost{3, 4, 3};
    EXPECT_EQ(canCompleteCircuit(gas, cost), -1);
}

TEST(GasStation, MultipleValidStarts_AllZeroNet) {
    // net = 0 everywhere => any start works; many solutions exist.
    // Usually expected is 0 (common convention).
    vector<int> gas {5, 5, 5, 5};
    vector<int> cost{5, 5, 5, 5};
    EXPECT_EQ(canCompleteCircuit(gas, cost), 0);
}

TEST(GasStation, MultipleValidStarts_AllPositiveNet) {
    // net > 0 everywhere => any start works; expected 0 by convention.
    vector<int> gas {3, 3, 3};
    vector<int> cost{1, 1, 1};
    EXPECT_EQ(canCompleteCircuit(gas, cost), 0);
}

TEST(GasStation, ValidStartIsNotWhereGasIsMax) {
    // Greedy trap: biggest gas station isn't necessarily the right start.
    vector<int> gas {10, 1, 1, 1};
    vector<int> cost{11, 1, 1, 0};
    // total gas = 13, total cost = 13 => solution exists.
    // Starting at 0 fails immediately (10 < 11). Correct start is 1.
    EXPECT_EQ(canCompleteCircuit(gas, cost), 1);
}

TEST(GasStation, SolutionAtLastIndex) {
    vector<int> gas {1, 1, 1, 10};
    vector<int> cost{2, 2, 2, 4};
    // total gas = 13, total cost = 10 => exists
    // indices 0,1,2 fail early; 3 works
    EXPECT_EQ(canCompleteCircuit(gas, cost), 3);
}

TEST(GasStation, ZerosMixedWithPositives) {
    vector<int> gas {0, 0, 5, 0, 0};
    vector<int> cost{0, 1, 1, 1, 1};
    // total gas=5 total cost=4 => exists; start at 2 should work
    EXPECT_EQ(canCompleteCircuit(gas, cost), 2);
}

TEST(GasStation, ManyFailuresBeforeSuccess) {
    // Designed so that early starts fail; later one works.
    vector<int> gas {1, 1, 1, 1, 8};
    vector<int> cost{2, 2, 2, 2, 1};
    EXPECT_EQ(canCompleteCircuit(gas, cost), 4);
}

TEST(GasStation, PrefixSumMinimumIdea) {
    // net: [-2, +3, -1, 0]
    // total net = 0 => exists; start should be 1 (after minimum prefix)
    vector<int> gas {1, 5, 2, 2};
    vector<int> cost{3, 2, 3, 2};
    EXPECT_EQ(canCompleteCircuit(gas, cost), 1);
}

TEST(GasStation, LargeValues_NoOverflowInIntermediateIfUsingLongLong) {
    // If someone accumulates in int, can overflow in larger constructed tests.
    // Here still within int sums per-step, but total can approach limits.
    vector<int> gas {INT_MAX, INT_MAX, INT_MAX};
    vector<int> cost{INT_MAX, INT_MAX, INT_MAX};
    EXPECT_EQ(canCompleteCircuit(gas, cost), 0);
}

TEST(GasStation, MediumRandomLikeCase) {
    vector<int> gas {4, 6, 7, 4};
    vector<int> cost{6, 5, 3, 5};
    // Known answer = 1
    EXPECT_EQ(canCompleteCircuit(gas, cost), 1);
}

TEST(GasStation, BiggerCase_SingleValidStart) {
    vector<int> gas  {2, 0, 1, 2, 3, 4, 0, 0, 5, 1};
    vector<int> cost {1, 1, 1, 3, 1, 1, 1, 1, 1, 4};
    // total gas = 18, total cost = 15 => exists
    // crafted so only a specific start survives (commonly 4)
    EXPECT_EQ(canCompleteCircuit(gas, cost), 4);
}

TEST(GasStation, Stress_LargeN_AllEqual) {
    const int n = 10000;
    vector<int> gas(n, 7);
    vector<int> cost(n, 7);
    EXPECT_EQ(canCompleteCircuit(gas, cost), 0);
}

TEST(GasStation, Stress_LargeN_NoSolution) {
    const int n = 10000;
    vector<int> gas(n, 1);
    vector<int> cost(n, 2);
    EXPECT_EQ(canCompleteCircuit(gas, cost), -1);
}

TEST(GasStation,Big_Sample_InterviewBit) {
    vector<int> gas {959, 329, 987, 951, 942, 410, 282, 376, 581, 507, 546, 299, 564, 114, 474, 163, 953, 481, 337, 395, 679, 21, 335, 846, 878, 961, 663, 413, 610, 937, 32, 831, 239, 899, 659, 718, 738, 7, 209};
    vector<int> cost {862, 783, 134, 441, 177, 416, 329, 43, 997, 920, 289, 117, 573, 672, 574, 797, 512, 887, 571, 657, 420, 686, 411, 817, 185, 326, 891, 122, 496, 905, 910, 810, 226, 462, 759, 637, 517, 237, 884};
    EXPECT_EQ(canCompleteCircuit(gas,cost),-1);
}
