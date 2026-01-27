#include "matrix/determinant.hpp"
#include <gtest/gtest.h>


TEST(Determinant,FromPaper)
{
    std::vector<std::vector<long long>> mat={{1,3,5},{2,0,4},{1,1,-2}};
    EXPECT_EQ(determinantBareiss(mat),30);
}


TEST(Determinant,ZeroFirstColumn)
{
    std::vector<std::vector<long long>> mat={{0,3,5},{0,0,4},{0,1,-2}};
    EXPECT_EQ(determinantBareiss(mat),0);
}

TEST(Determinant,FourByFour)
{
    std::vector<std::vector<long long>> mat={{2,1,3,4},{1,0,2,1},{3,2,1,0},{4,1,0,2}};
    EXPECT_EQ(determinantBareiss(mat),37);
}

TEST(Determinant, NoSquareMatrix)
{
    std::vector<std::vector<long long>> mat={{1,3,5},{2,0,4}};
    EXPECT_THROW(determinantBareiss(mat),std::exception);
}