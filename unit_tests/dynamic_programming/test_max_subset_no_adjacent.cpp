#include "dynamic_programming/max_subset_no_adjacent.hpp"
#include <gtest/gtest.h>


TEST(MaxSubsetNoAdjustment,EmptyVec)
{   std::vector<int> v1={};
    EXPECT_EQ(maxSubsetSumNoAdjacent(v1),0);
}


TEST(MaxSubsetNoAdjustment,BaseCase)
{   std::vector<int> v1={75,105,120,75,90,135};
    EXPECT_EQ(maxSubsetSumNoAdjacent(v1),330);
}

TEST(MaxSubsetNoAdjustment, SingleElement)
{
    std::vector<int> v = {7};
    EXPECT_EQ(maxSubsetSumNoAdjacent(v), 7);
}

TEST(MaxSubsetNoAdjustment, TwoElementsPickMax)
{
    std::vector<int> v = {5, 10};
    EXPECT_EQ(maxSubsetSumNoAdjacent(v), 10);
}

TEST(MaxSubsetNoAdjustment, TwoElementsEqual)
{
    std::vector<int> v = {9, 9};
    EXPECT_EQ(maxSubsetSumNoAdjacent(v), 9);
}

TEST(MaxSubsetNoAdjustment, AllZeros)
{
    std::vector<int> v = {0, 0, 0, 0, 0};
    EXPECT_EQ(maxSubsetSumNoAdjacent(v), 0);
}

TEST(MaxSubsetNoAdjustment, SimpleIncreasing)
{
    // best: 2 + 4 = 6
    std::vector<int> v = {1, 2, 3, 4};
    EXPECT_EQ(maxSubsetSumNoAdjacent(v), 6);
}

TEST(MaxSubsetNoAdjustment, SimpleDecreasing)
{
    // best: 9 + 7 + 5 = 21
    std::vector<int> v = {9, 8, 7, 6, 5};
    EXPECT_EQ(maxSubsetSumNoAdjacent(v), 21);
}

TEST(MaxSubsetNoAdjustment, AlternatingHighLow)
{
    // best: 10 + 10 + 10 = 30
    std::vector<int> v = {10, 1, 10, 1, 10};
    EXPECT_EQ(maxSubsetSumNoAdjacent(v), 30);
}

TEST(MaxSubsetNoAdjustment, ContainsZerosBetweenPositives)
{
    // best: 5 + 7 = 12 (or 5+0+7 still 12)
    std::vector<int> v = {5, 0, 0, 7};
    EXPECT_EQ(maxSubsetSumNoAdjacent(v), 12);
}

TEST(MaxSubsetNoAdjustment, PicksNonGreedy)
{
    // Greedy picking 10 then 1 then 1 -> 12 is wrong
    // best: 1 + 10 + 1 = 12? wait adjacency: indices 0,2,4 => 1+10+1=12
    // but also 10+1 (idx1+idx3)=11, so best is 12
    std::vector<int> v = {1, 10, 10, 1, 1};
    EXPECT_EQ(maxSubsetSumNoAdjacent(v), 12);
}

TEST(MaxSubsetNoAdjustment, ClassicExample)
{
    // best: 3 + 5 + 7 = 15
    std::vector<int> v = {3, 2, 5, 10, 7};
    EXPECT_EQ(maxSubsetSumNoAdjacent(v), 15);
}

TEST(MaxSubsetNoAdjustment, ManySameValuesOddCount)
{
    // best: pick ceil(n/2) * val = 3 * 4 = 12
    std::vector<int> v = {4, 4, 4, 4, 4};
    EXPECT_EQ(maxSubsetSumNoAdjacent(v), 12);
}

TEST(MaxSubsetNoAdjustment, ManySameValuesEvenCount)
{
    // best: pick n/2 * val = 3 * 6 = 18
    std::vector<int> v = {6, 6, 6, 6, 6, 6};
    EXPECT_EQ(maxSubsetSumNoAdjacent(v), 18);
}

TEST(MaxSubsetNoAdjustment, LargeValuesNoOverflowInInt64Reference)
{
    // If your implementation uses int, this might overflow.
    // Keep it as a "stress" test; if you want it always safe, change function to return long long.
    const int A = 1'000'000'000;
    std::vector<int> v = {A, 0, A, 0, A}; // best: 3e9
    // Expected mathematically:
    // If maxSubsetSumNoAdjacent returns int, behavior may overflow; adjust if using long long.
    // Here we still assert on the mathematical answer casted to long long if you change signature.
    EXPECT_EQ((long long)maxSubsetSumNoAdjacent(v), 3'000'000'000LL);
}

TEST(MaxSubsetNoAdjustment, MediumSizedPattern)
{
    // pattern: 8,1,1,8,1,1,8 => best: 8+8+8=24
    std::vector<int> v = {8, 1, 1, 8, 1, 1, 8};
    EXPECT_EQ(maxSubsetSumNoAdjacent(v), 24);
}

TEST(MaxSubsetNoAdjustment, BiggerSample)
{
    // best picks all 5's at even indices: 10 of them => 50
    std::vector<int> v;
    for (int i = 0; i < 20; ++i) v.push_back((i % 2 == 0) ? 5 : 1);
    EXPECT_EQ(maxSubsetSumNoAdjacent(v), 50);
}