#include "math_and_geometry/most_distance.hpp"
#include <gtest/gtest.h>
#include <vector>

using namespace std;

TEST(MostDistance,LongestOnX)
{
    vector<vector<int>> points={{0,1},{2,0},{-5,0},{9,0},{0,-7}};
    double res=mostDistance(points);
    EXPECT_NEAR(res,14.0,1e-6);
}

TEST(MostDistance,LongestOnY)
{
    vector<vector<int>> points={{0,100},{2,0},{-5,0},{9,0},{0,-100}};
    double res=mostDistance(points);
    EXPECT_NEAR(res,200.0,1e-6);
}

TEST(MostDistance,BiggestDistanceInCorners)
{
    vector<vector<int>> points={{0,-5},{-7,0},{0,-6},{-4,0},{0,0}};
    double actual=mostDistance(points);
    double expected =9.219544457293;
    EXPECT_NEAR(actual,expected,1e-6);


}