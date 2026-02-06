

#include "numbers_theory/restaurant.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"
#include <string>
//data/hacker_rank_input_for_ut

std::vector<std::vector<std::string>>rawInput=readInputFileClassic("data/hacker_rank_input_for_ut/restaurant.txt");
int nbOfTests=rawInput.size();
TEST(Restaurant,TrivalCase)
{   std::vector<int> expected={1,6};
    for (int i = 0; i < nbOfTests; ++i)
    {
        std::vector<std::string>testCase=rawInput[i];
        int l=stoi(rawInput[i][0]);
        int b=stoi(rawInput[i][1]);
        int actual=restaurant(l,b);
        EXPECT_EQ(actual,expected[i]);
    }
}


TEST(Restaurant, UnitSquare_1x1) {
    EXPECT_EQ(restaurant(1, 1), 1);
}

TEST(Restaurant, SameSides_SingleSquare) {
    EXPECT_EQ(restaurant(7, 7), 1);
    EXPECT_EQ(restaurant(100, 100), 1);
}

TEST(Restaurant, OneSideIsMultiple) {
    EXPECT_EQ(restaurant(2, 4), 2);
    EXPECT_EQ(restaurant(3, 12), 4);
    EXPECT_EQ(restaurant(5, 20), 4);
}

TEST(Restaurant, CoprimeSides_ProductSquares) {
    EXPECT_EQ(restaurant(2, 3), 6);
    EXPECT_EQ(restaurant(8, 15), 120); // gcd=1 => 8*15
}

TEST(Restaurant, Commutative) {
    EXPECT_EQ(restaurant(6, 10), restaurant(10, 6));
    EXPECT_EQ(restaurant(9, 12), restaurant(12, 9));
}

// ------------------------
// Edge-ish cases / contract
// (If your implementation doesn't define behavior for <=0,
// these tests will likely fail and push you to add guards.)
// ------------------------

TEST(Restaurant, ZeroDimension_ShouldBeZero) {
    EXPECT_EQ(restaurant(0, 5), 0);
    EXPECT_EQ(restaurant(7, 0), 0);
    EXPECT_EQ(restaurant(0, 0), 0);
}

TEST(Restaurant, NegativeDimension_ShouldBeZero) {
    EXPECT_EQ(restaurant(-5, 10), 0);
    EXPECT_EQ(restaurant(5, -10), 0);
    EXPECT_EQ(restaurant(-5, -10), 0);
}