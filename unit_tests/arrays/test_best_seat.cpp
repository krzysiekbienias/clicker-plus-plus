#include "arrays/best_seat.hpp"
#include <gtest/gtest.h>


TEST(BestSeat,TrivalCase)
{
    EXPECT_EQ(bestSeat({1,0,1,0,0,0,1}),4);
}

TEST(BestSeat,LongRow)
{
    EXPECT_EQ(bestSeat({1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1}),13);
}