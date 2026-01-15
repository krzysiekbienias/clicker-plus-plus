#include <gmock/gmock-matchers.h>

#include "two_pointers/container_with_most_water.hpp"
#include <gtest/gtest.h>


TEST(ContainerWithMostWater,EmptyVec)
{
    std::vector<int> v={};
    EXPECT_EQ(containerWithMostWatter(v),0);
}

TEST(ContainerWithMostWater,TrivalCase)
{
    std::vector<int> v={1,8,6,2,5,4,8,3,7};
    EXPECT_EQ(containerWithMostWatter(v),49);
}