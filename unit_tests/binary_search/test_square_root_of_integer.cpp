#include "binary_search/square_root_of_integer.hpp"
#include <gtest/gtest.h>

#include <climits>

// --------------------
// Trivial inputs
// --------------------
TEST(SquareRootOfInteger, Zero) {
    EXPECT_EQ(mySqrt(0), 0);
}

TEST(SquareRootOfInteger, One) {
    EXPECT_EQ(mySqrt(1), 1);
}

// --------------------
// Just above a perfect square
// --------------------
TEST(SquareRootOfInteger, TwoFloorsToOne) {
    EXPECT_EQ(mySqrt(2), 1);
}

TEST(SquareRootOfInteger, ThreeFloorsToOne) {
    EXPECT_EQ(mySqrt(3), 1);
}

TEST(SquareRootOfInteger, EightFloorsToTwo) {
    EXPECT_EQ(mySqrt(8), 2);
}

TEST(SquareRootOfInteger, FifteenFloorsToThree) {
    EXPECT_EQ(mySqrt(15), 3);
}

// --------------------
// Perfect squares
// --------------------
TEST(SquareRootOfInteger, PerfectSquareFour) {
    EXPECT_EQ(mySqrt(4), 2);
}

TEST(SquareRootOfInteger, PerfectSquareNine) {
    EXPECT_EQ(mySqrt(9), 3);
}

TEST(SquareRootOfInteger, PerfectSquareSixteen) {
    EXPECT_EQ(mySqrt(16), 4);
}

TEST(SquareRootOfInteger, PerfectSquareHundred) {
    EXPECT_EQ(mySqrt(100), 10);
}

TEST(SquareRootOfInteger, PerfectSquareLarge) {
    EXPECT_EQ(mySqrt(12321), 111);
}

// --------------------
// One below and one above a perfect square
// --------------------
TEST(SquareRootOfInteger, JustBelowPerfectSquare) {
    EXPECT_EQ(mySqrt(99), 9);
    EXPECT_EQ(mySqrt(80), 8);
    EXPECT_EQ(mySqrt(12320), 110);
}

TEST(SquareRootOfInteger, JustAbovePerfectSquare) {
    EXPECT_EQ(mySqrt(101), 10);
    EXPECT_EQ(mySqrt(82), 9);
    EXPECT_EQ(mySqrt(12322), 111);
}

// --------------------
// int range: 46340^2 fits, 46341^2 does not
// --------------------
TEST(SquareRootOfInteger, LargestPerfectSquareInInt) {
    EXPECT_EQ(mySqrt(46340LL * 46340LL), 46340);
}

TEST(SquareRootOfInteger, JustBelowLargestPerfectSquare) {
    EXPECT_EQ(mySqrt(46340LL * 46340LL - 1), 46339);
}

TEST(SquareRootOfInteger, IntMax) {
    EXPECT_EQ(mySqrt(INT_MAX), 46340);
}
