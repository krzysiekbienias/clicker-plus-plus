#include "arrays/absent_term_in_arithmetic_series.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt


TEST(AbsentTermInSeries,Increasing)
{
    std::vector<int> vec{2,5,8,11,17,20};
    int actual=missingNumberInArithmetic(vec);
    EXPECT_EQ(actual,14);

}


TEST(AbsentTermInSeries,Decreasing)
{
    std::vector<int> vec{15,13,12};
    int actual=missingNumberInArithmetic(vec);
    EXPECT_EQ(actual,14);

}

TEST(AbsentTermInSeries,Decreasing2)
{
    std::vector<int> vec{20,15,10,0};
    int actual=missingNumberInArithmetic(vec);
    EXPECT_EQ(actual,5);

}