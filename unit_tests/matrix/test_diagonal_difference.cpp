#include "matrix/diagonal_difference.hpp"
#include <gtest/gtest.h>

using namespace std;

TEST (DiagonalDiff,TrivalCase)
{
    vector<vector<int>> mat={
        {11,2,4},
        {4,5,6},
        {10,8,-12}
    };
    int expected=15;
    int actual=diagonalDifference(mat);
    EXPECT_EQ(expected,actual);
}


TEST (DiagonalDiff,OddDiff)
{
    vector<vector<int>> mat={
        {11,2,4,6},
        {4,5,6,9},
        {10,8,-12,0},
        {1,0,10,0}
    };
    int expected=17;
    int actual=diagonalDifference(mat);
    EXPECT_EQ(expected,actual);
}