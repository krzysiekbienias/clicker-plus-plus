#include "sliding_window/bookstore_mood_shift.hpp"

#include <gtest/gtest.h>
#include <vector>

namespace {

int callMaxSatisfied(std::vector<int> customers, std::vector<int> grumpy, int minutes)
{
    return maxSatisfied(customers, grumpy, minutes);
}

} // namespace

TEST(BookstoreMoodShift, LeetCodeExample)
{
    EXPECT_EQ(callMaxSatisfied({1, 0, 1, 2, 1, 1, 7, 5}, {0, 1, 0, 1, 0, 1, 0, 1}, 3), 16);
}

TEST(BookstoreMoodShift, AllOwnerCalm_NoExtraGain)
{
    EXPECT_EQ(callMaxSatisfied({3, 4, 5}, {0, 0, 0}, 2), 12);
}

TEST(BookstoreMoodShift, AllOwnerGrumpy_BestWindowRecoversCustomers)
{
    EXPECT_EQ(callMaxSatisfied({1, 2, 3}, {1, 1, 1}, 2), 5);
}

TEST(BookstoreMoodShift, TechniqueLengthOne)
{
    EXPECT_EQ(callMaxSatisfied({5, 10, 5}, {1, 0, 1}, 1), 15);
}

TEST(BookstoreMoodShift, TechniqueCoversEntireDay)
{
    EXPECT_EQ(callMaxSatisfied({1, 0, 1}, {0, 1, 0}, 5), 2);
}

TEST(BookstoreMoodShift, SingleMinuteGrumpy)
{
    EXPECT_EQ(callMaxSatisfied({7}, {1}, 1), 7);
}

TEST(BookstoreMoodShift, SingleMinuteCalm)
{
    EXPECT_EQ(callMaxSatisfied({7}, {0}, 1), 7);
}

TEST(BookstoreMoodShift, ZeroCustomersOnGrumpyMinutes)
{
    EXPECT_EQ(callMaxSatisfied({0, 5, 0}, {1, 0, 1}, 2), 5);
}

TEST(BookstoreMoodShift, WindowWithNoGrumpyMinutesInside)
{
    EXPECT_EQ(callMaxSatisfied({9, 1, 9}, {0, 0, 0}, 2), 19);
}

TEST(BookstoreMoodShift, BestWindowNotAtTheEnd)
{
    EXPECT_EQ(callMaxSatisfied({15, 0, 0, 4}, {1, 0, 0, 1}, 3), 15);
}
