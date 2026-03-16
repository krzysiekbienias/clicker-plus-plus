#include "greedy/irrigation_relay.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

TEST(IrrigationRelay,TerminalBase)
{
    int actual= wateringPlants({2,2,3,3},5);
    EXPECT_EQ(actual,14); //1+1+2+3+3+4

}

TEST(IrrigationRelay,SinglePlantExactCapacity)
{
    int actual = wateringPlants({5}, 5);
    EXPECT_EQ(actual, 1);
}

TEST(IrrigationRelay,SinglePlantLessThanCapacity)
{
    int actual = wateringPlants({2}, 5);
    EXPECT_EQ(actual, 1);
}

TEST(IrrigationRelay,NoRefillNeededAtAll)
{
    int actual = wateringPlants({1,1,1,1}, 5);
    EXPECT_EQ(actual, 4);
}

TEST(IrrigationRelay,RefillBeforeLastPlant)
{
    int actual = wateringPlants({2,2,3}, 4);
    EXPECT_EQ(actual, 7);

}

TEST(IrrigationRelay,RefillEveryTimeAfterFirst)
{
    int actual = wateringPlants({1,1,1,1}, 1);
    EXPECT_EQ(actual, 16);
    // plant0: 1
    // refill trips before plant1, plant2, plant3:
    // +2, +4, +6
    // plus forward moves already counted through traversal
}

TEST(IrrigationRelay,ExactRefillPattern)
{
    int actual = wateringPlants({3,3,3}, 6);
    EXPECT_EQ(actual, 7);
    // 1 to plant0, 1 to plant1, refill before plant2 => +4, total 7
}

TEST(IrrigationRelay,CapacityMatchesEachPlantButNeedsRefills)
{
    int actual = wateringPlants({4,4,4}, 4);
    EXPECT_EQ(actual, 9);
}

TEST(IrrigationRelay,RefillRightBeforeFinalPlant)
{
    int actual = wateringPlants({1,2,4,4,5}, 6);
    EXPECT_EQ(actual, 23);
}

TEST(IrrigationRelay,MinimumCase)
{
    int actual = wateringPlants({1}, 1);
    EXPECT_EQ(actual, 1);
}

TEST(IrrigationRelay,TwoPlantsExactAfterFirst)
{
    int actual = wateringPlants({2,3}, 5);
    EXPECT_EQ(actual, 2);
}

TEST(IrrigationRelay,TwoPlantsNeedRefill)
{
    int actual = wateringPlants({3,3}, 5);
    EXPECT_EQ(actual, 4);
    // plant0 = 1
    // refill before plant1: back 1, forward 2, total = 6
}

TEST(IrrigationRelay,MultipleSmallRefills)
{
    int actual = wateringPlants({2,1,1,2}, 3);
    EXPECT_EQ(actual, 8);
}