#include <gtest/gtest.h>

#include "math_and_geometry/line_through_points.hpp"


TEST(LineThroughPoints,SeveralPointsFromPlatform)
{
    std::vector<std::vector<int>> vecPoints={
        {1,1},
        {2,2,},
        {3,3},
        {0,4},
        {-2,6},
        {4,0},
        {2,1},
    };
    int actual=lineThroughPoints(vecPoints);
    EXPECT_EQ(actual,4);
}


TEST(LineThroughPoints,ThreePointsOnOneLine)
{
    std::vector<std::vector<int>> vecPoints={
        {1,1},
        {2,2,},
        {3,3},
    };
    int actual=lineThroughPoints(vecPoints);
    EXPECT_EQ(actual,3);
}


TEST(LineThroughPoints,OnlyOne)
{
    std::vector<std::vector<int>> vecPoints={
        {1,1},

    };
    int actual=lineThroughPoints(vecPoints);
    EXPECT_EQ(actual,1);
}

TEST(LineThroughPoints,NoPoints)
{
    std::vector<std::vector<int>> vecPoints={


    };
    int actual=lineThroughPoints(vecPoints);
    EXPECT_EQ(actual,0);
}