#include "heap/kClosestPoint.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt
using::testing ::ElementsAre;

TEST(KClosestPointIn2D,TrivalCase)
{
    std::vector<std::vector<int>> in2={{3,3},{5,-1},{-2,4}};
    std::vector<std::vector<int>> actual=kClosestPoint(in2,2);
    std::vector<std::vector<int>> expected={{-2,4},{3,3}};
    EXPECT_THAT(actual,expected);

}

TEST(KClosestPointIn2D,TrivalCase2)
{
    std::vector<std::vector<int>> in2={{1,3},{-2,2}};
    std::vector<std::vector<int>> actual=kClosestPoint(in2,1);
    std::vector<std::vector<int>> expected={{-2,2}};
    EXPECT_THAT(actual,expected);

}