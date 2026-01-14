#include "dynamic_programming/water_area.hpp"
#include <gtest/gtest.h>

TEST(WaterArea,EmptyString)
{
    std::vector<int> v;
    EXPECT_EQ(waterArea(v),0);
}

TEST(WaterArea,LessThan1)
{
    std::vector<int> v={2};
    EXPECT_EQ(waterArea(v),0);
}

TEST(WaterArea,OnlyZeros)
{
    std::vector<int> v={0,0,0,0,0};
    EXPECT_EQ(waterArea(v),0);
}

TEST(WaterArea,Basic)
{
    std::vector<int> v={0,8,0,0,5,0,0,10,0,0,1,1,0,3};
    EXPECT_EQ(waterArea(v),48);
}

TEST(WaterArea,TwoWalls)
{
    std::vector<int> v={8,0,0,0,0,0,0,0,0,0,0,0,0,3};
    EXPECT_EQ(waterArea(v),36);
}

TEST(WaterArea,TwoWallsAndPillarInTheMiddle)
{
    std::vector<int> v={8,0,0,0,0,0,2,0,0,0,0,0,0,3};
    EXPECT_EQ(waterArea(v),34);
}