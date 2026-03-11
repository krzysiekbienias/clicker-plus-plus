#include "stack/daily_temperatures.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::ElementsAre;

TEST(DailyTemp,TrivalCase)
{
    std::vector<int> temps={73,74,75,71,69,72,76,73};
    std::vector<int> actual=dailyTemperatures(temps);
    std::vector<int> expected={1,1,4,2,1,1,0,0};

    EXPECT_THAT(actual,expected);
}

TEST(DailyTemp, EmptyInput)
{
    std::vector<int> temps = {};
    std::vector<int> actual = dailyTemperatures(temps);
    std::vector<int> expected = {};

    EXPECT_EQ(actual, expected);
}

TEST(DailyTemp, SingleDay)
{
    std::vector<int> temps = {42};
    std::vector<int> actual = dailyTemperatures(temps);
    std::vector<int> expected = {0};

    EXPECT_EQ(actual, expected);
}

TEST(DailyTemp, StrictlyIncreasing)
{
    std::vector<int> temps = {30, 40, 50, 60};
    std::vector<int> actual = dailyTemperatures(temps);
    std::vector<int> expected = {1, 1, 1, 0};

    EXPECT_EQ(actual, expected);
}

TEST(DailyTemp, StrictlyDecreasing)
{
    std::vector<int> temps = {60, 50, 40, 30};
    std::vector<int> actual = dailyTemperatures(temps);
    std::vector<int> expected = {0, 0, 0, 0};

    EXPECT_EQ(actual, expected);
}

TEST(DailyTemp, AllEqualTemperatures)
{
    std::vector<int> temps = {70, 70, 70, 70};
    std::vector<int> actual = dailyTemperatures(temps);
    std::vector<int> expected = {0, 0, 0, 0};

    EXPECT_EQ(actual, expected);
}

TEST(DailyTemp, WarmerDayAfterSeveralColderDays)
{
    std::vector<int> temps = {70, 69, 68, 71};
    std::vector<int> actual = dailyTemperatures(temps);
    std::vector<int> expected = {3, 2, 1, 0};

    EXPECT_EQ(actual, expected);
}

TEST(DailyTemp, EqualValuesBeforeWarmerDay)
{
    std::vector<int> temps = {70, 70, 71};
    std::vector<int> actual = dailyTemperatures(temps);
    std::vector<int> expected = {2, 1, 0};

    EXPECT_EQ(actual, expected);
}

TEST(DailyTemp, MixedCaseWithLateWarmerDay)
{
    std::vector<int> temps = {75, 71, 69, 72, 76};
    std::vector<int> actual = dailyTemperatures(temps);
    std::vector<int> expected = {4, 2, 1, 1, 0};

    EXPECT_EQ(actual, expected);
}