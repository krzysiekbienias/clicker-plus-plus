#include <gmock/gmock-matchers.h>

#include "queue/min_value_of_each_n_elements.hpp"
#include <gtest/gtest.h>

using testing::ElementsAre;

TEST(MinValueOfEachNElement,TwoElementsWindow)
{
EXPECT_THAT(minValue({ 1, -2, 3, -4, 5, -6, 7, 8 },2),ElementsAre(-2, -2, -4, -4, -6, -6, 7 ));
}

TEST(MinValueOfEachNElement,ThreeElements)
{
    EXPECT_THAT(minValue({ 1, -2, 3, -4, 5, -6, 7, 8 },3),ElementsAre(-2, -4, -4, -6, -6, -6 ));
}

TEST(MinValueOfEachNElement,Singletons)
{
    EXPECT_THAT(minValue({ 1, -2, 3, -4, 5, -6, 7, 8 },1),ElementsAre(1, -2, 3, -4, 5, -6, 7, 8 ));
}