#include "arrays/add_one_to_number.hpp"
#include <gtest/gtest.h>

#include <gmock/gmock.h>

using ::testing::ElementsAre;
using ::testing::ElementsAreArray;

TEST(PlusOne,EmptyVector)
{
    std::vector<int> v1={};
    EXPECT_EQ(plusOne(v1),std::vector<int>{});

}


TEST(PlusOne,TrivalCase)
{
    std::vector<int> v1={4,3,3};
    std::vector<int> v2={1,2,3};
    EXPECT_THAT(plusOne(v1),ElementsAre(4,3,4));
    EXPECT_THAT(plusOne(v2),ElementsAre(1,2,4));
}

TEST(PlusOne,only9s)
{
    std::vector<int> v1={9,9};
    std::vector<int> v2={9,9,9,9,9};
    EXPECT_THAT(plusOne(v1),ElementsAre(1,0,0));
    EXPECT_THAT(plusOne(v2),ElementsAre(1,0,0,0,0,0));
}

TEST(PlusOne,zeroPrefex)
{
    std::vector<int> v1={0,3,7,6,4,0,5,5,5};

    EXPECT_THAT(plusOne(v1),ElementsAre(3,7,6,4,0,5,5,6));

}