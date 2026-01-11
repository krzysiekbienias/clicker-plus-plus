#include <gmock/gmock-matchers.h>

#include "arrays/largest_range.hpp"
#include <gtest/gtest.h>
using ::testing::ElementsAre;

TEST(LargestRange,EmptyVec)
{   std::vector<int> v1={};
    EXPECT_EQ(largestRange(v1),std::vector<int>{});
}

TEST(LargestRange,NoGap)
{   std::vector<int> v1={1,2,3};
   std::vector<int> v2={9,8,7,6,5};
    EXPECT_THAT(largestRange(v1),ElementsAre(1,3));
    EXPECT_THAT(largestRange(v2),ElementsAre(5,9));
}

TEST(LargestRange,Gap)
{   std::vector<int> v1={1,11,3,0,15,5,2,4,10,7,12,6};

    EXPECT_THAT(largestRange(v1),ElementsAre(0,7));

}