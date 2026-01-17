#include "bit_manipulation/convert_date_to_binary.hpp"
#include <gtest/gtest.h>


TEST(DateToBinary,EmptyStr)
{
    std::string date="";
    EXPECT_EQ(convertDateToBinary(date),"0");
}

TEST(DateToBinary,BaseCase)
{
    std::string date="2080-02-29";
    EXPECT_EQ(convertDateToBinary(date),"100000100000-10-11101");
}