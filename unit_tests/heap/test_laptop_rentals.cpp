#include "heap/laptop_rentals.hpp"

#include <gtest/gtest.h>
#include <vector>

using std::vector;

namespace {

int callLaptopRentals(vector<vector<int>> times)
{
    return laptopRentals(std::move(times));
}

} // namespace

TEST(LaptopRentals, InterviewBitExample)
{
    vector<vector<int>> times = {
        {0, 2}, {1, 4}, {4, 6}, {0, 4}, {7, 8}, {9, 11}, {3, 10},
    };
    EXPECT_EQ(callLaptopRentals(times), 3);
}

TEST(LaptopRentals, EmptyInput_ReturnsZero)
{
    EXPECT_EQ(callLaptopRentals({}), 0);
}

TEST(LaptopRentals, SingleInterval_ReturnsOne)
{
    EXPECT_EQ(callLaptopRentals({{0, 5}}), 1);
}

TEST(LaptopRentals, NonOverlappingIntervals_ReturnsOne)
{
    EXPECT_EQ(callLaptopRentals({{0, 2}, {2, 4}, {4, 6}}), 1);
}

TEST(LaptopRentals, TouchingIntervalsShareOneLaptop)
{
    // [2, 5) and [5, 9) overlap only at a boundary point that frees the laptop.
    EXPECT_EQ(callLaptopRentals({{2, 5}, {5, 9}}), 1);
}

TEST(LaptopRentals, TwoFullyOverlappingIntervals_ReturnsTwo)
{
    EXPECT_EQ(callLaptopRentals({{1, 10}, {2, 8}}), 2);
}

TEST(LaptopRentals, AllStartAtSameTime_ReturnsCount)
{
    EXPECT_EQ(callLaptopRentals({{0, 3}, {0, 4}, {0, 5}}), 3);
}

TEST(LaptopRentals, NestedIntervals_ReturnsThree)
{
    EXPECT_EQ(callLaptopRentals({{0, 10}, {2, 4}, {3, 5}}), 3);
}

TEST(LaptopRentals, PeakInTheMiddle_NotAtTheEnd)
{
    EXPECT_EQ(callLaptopRentals({{0, 10}, {1, 2}, {1, 3}, {8, 9}}), 3);
}

TEST(LaptopRentals, LargeTimeValues_StillCorrect)
{
    EXPECT_EQ(callLaptopRentals({{100, 200}, {150, 250}, {200, 300}}), 2);
}

TEST(LaptopRentals, UnsortedInput_StillCorrect)
{
    vector<vector<int>> times = {
        {7, 8}, {0, 4}, {9, 11}, {1, 4}, {4, 6}, {3, 10}, {0, 2},
    };
    EXPECT_EQ(callLaptopRentals(times), 3);
}

TEST(LaptopRentals, ManyShortIntervalsAtSamePoint)
{
    EXPECT_EQ(callLaptopRentals({{5, 6}, {5, 7}, {5, 8}, {5, 9}}), 4);
}
