#include "arrays/car_park_escape.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using::testing::ElementsAre;

TEST(EscapeFromPark,StraigtToExit)
{
    EXPECT_THAT(escape({{0,0,2,0,0,0,0,0}}),ElementsAre("R5"));
}


TEST(EscapeFromPark, TrivalCase)
{
    EXPECT_THAT(escape({{1, 0, 0, 0, 2},
                                    {0, 0, 0, 0, 0}}), ElementsAre("L4","D1","R4"));
}


TEST(EscapeFromPark, TrivalCase2)
{
    EXPECT_THAT(escape({{2, 0, 0, 1, 0},
                                    {0, 0, 0, 1, 0},
                                    {0, 0, 0, 0, 0}}), ElementsAre("R3","D2","R1"));
}


TEST(EscapeFromPark, StrictToExit)
{
    EXPECT_THAT(escape({ {0, 2, 0, 0, 1},
                                    {0, 0, 0, 0, 1},
                                    {0, 0, 0, 0, 1},
                                    {0, 0, 0, 0, 0}}), ElementsAre("R3","D3"));
}

TEST(EscapeFromPark, ZigZag)
{
    EXPECT_THAT(escape({ {1, 0, 0, 0, 2},
                                    {0, 0, 0, 0, 1},
                                    {1, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0}}), ElementsAre("L4","D1","R4","D1","L4","D1","R4"));
}

TEST(EscapeFromPark, OneLevel)
{
    EXPECT_THAT(escape({{0, 0, 0, 0, 2}}), testing::IsEmpty());
}