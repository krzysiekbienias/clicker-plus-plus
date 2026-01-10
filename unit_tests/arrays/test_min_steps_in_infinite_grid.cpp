#include "arrays/min_steps_in_infinite_grid.hpp"
#include <gtest/gtest.h>


TEST (InfiniteGrid,EmptyVec)
{
    EXPECT_EQ(minStepsInInfiniteGrid({},{}),0);
}


TEST (InfiniteGrid,Base)
{
    EXPECT_EQ(minStepsInInfiniteGrid({0,1,1},{0,1,2}),2);
}


