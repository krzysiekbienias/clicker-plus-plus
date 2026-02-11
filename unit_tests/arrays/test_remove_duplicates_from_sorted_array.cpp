#include <gmock/gmock-matchers.h>

#include "arrays/remove_duplicates_from_sorted_array.hpp"
#include <gtest/gtest.h>


TEST(DuplicatesFromSortedArrayLen,TrivalCase)
{
    std::vector<int> vec={1,2,2,3,3};
    int len=removeDuplicatesFromSortedArray(vec);

    EXPECT_EQ(len,3);
    EXPECT_EQ(vec[0],1);
    EXPECT_EQ(vec[1],2);
    EXPECT_EQ(vec[2],3);

}

TEST(DuplicatesFromSortedArrayTwiceAllowedLen,TrivalCase)
{
    std::vector<int> vec={1,2,2,3,3};
    int len=removeDuplicatesFromSortedArray(vec);

    EXPECT_EQ(len,5);
    EXPECT_EQ(vec[0],1);
    EXPECT_EQ(vec[1],2);
    EXPECT_EQ(vec[1],2);
    EXPECT_EQ(vec[2],3);
    EXPECT_EQ(vec[2],3);

}


TEST(DuplicatesFromSortedArrayTwiceAllowedLen,EarlyExit)
{
    std::vector<int> vec={1,2};
    std::vector<int> singleton={10};
    int len=removeDuplicatesFromSortedArrayTwiceAllowed(vec);

    EXPECT_EQ(len,2);
    EXPECT_EQ(vec[0],1);
    EXPECT_EQ(vec[1],2);

    EXPECT_EQ(removeDuplicatesFromSortedArrayTwiceAllowed(singleton),1);



}