#include "hash_maps_and_sets/occurence_of_each_number.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::ElementsAre;
using ::testing::UnorderedElementsAre;

TEST(OccurenceEachNumber,EmptyVec)
{
    std::vector<int> v1;
    EXPECT_EQ(findOccurences(v1),std::vector<int> {});
}

TEST(OccurenceEachNumber,TrivalCase)
{
std::vector<int> v1={4,3,3};
std::vector<int> v2={1,2,3};
    EXPECT_THAT(findOccurences(v1),ElementsAre(2,1));
    EXPECT_THAT(findOccurences(v2),ElementsAre(1,1,1));
}