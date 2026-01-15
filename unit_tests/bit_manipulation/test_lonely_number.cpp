#include "bit_manipulation/lonely_number.hpp"

#include <gtest/gtest.h>
#include <vector>


TEST(LonelyNumber,TrivalCase){
    std::vector<int> v{1,3,3,2,1};
    EXPECT_EQ(lonelyNumber(v),2);
}