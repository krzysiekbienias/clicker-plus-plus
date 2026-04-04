#include "greedy/array_gap_minimization.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

TEST(GapMinimizationTest, BasicFunctionality) {
    std::vector<int> nums = {1, 3, 6};
    EXPECT_EQ(gapMinimization(nums, 3), 3);
}

TEST(GapMinimizationTest, SingleElementReturnsZero) {
    std::vector<int> nums = {10};
    EXPECT_EQ(gapMinimization(nums, 2), 0);
}

TEST(GapMinimizationTest, ReducesGapEffectively) {
    std::vector<int> nums = {1, 10};
    // Zwiększamy 1 o 4 (-> 5), zmniejszamy 10 o 4 (-> 6).
    // Nowy zakres to [5, 6], czyli różnica wynosi 1.
    EXPECT_EQ(gapMinimization(nums, 4), 1);
}

TEST(GapMinimizationTest, SuboptimalKValue) {
    std::vector<int> nums = {0, 10};
    // k jest za małe, żeby zniwelować różnicę.
    // [0+2, 10-2] -> [2, 8] -> różnica 6.
    EXPECT_EQ(gapMinimization(nums, 2), 6);
}

TEST(GapMinimizationTest, IdenticalElements) {
    std::vector<int> nums = {7, 7, 7};
    // Dla identycznych elementów różnica zawsze powinna wynosić 0,
    // niezależnie od tego, o ile je przesuwamy.
    EXPECT_EQ(gapMinimization(nums, 10), 0);
}

TEST(GapMinimizationTest, NegativeNumbers) {
    std::vector<int> nums = {-5, -2, 4};
    // Radzenie sobie z ujemnymi wartościami i przekraczaniem zera.
    // Optymalny podział: zwiększamy -5 i -2 (-> -2, 1), zmniejszamy 4 (-> 1).
    // Nowy zakres: min=-2, max=1. Różnica wynosi 3.
    EXPECT_EQ(gapMinimization(nums, 3), 3);
}

TEST(GapMinimizationTest, NoChangeIsOptimal) {
    std::vector<int> nums = {1, 2, 3};
    // Kiedy k jest równe 0, po prostu zwracamy pierwotną różnicę.
    EXPECT_EQ(gapMinimization(nums, 0), 2);
}