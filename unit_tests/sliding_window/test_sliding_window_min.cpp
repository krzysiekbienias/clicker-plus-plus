#include "sliding_window/sliding_window_min.hpp"

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

using testing::ElementsAre;

TEST(SlidingWindowMin, ClassicExample) {
    EXPECT_THAT(
        slidingWindowMin({1, 3, -1, -3, 5, 3, 6, 7}, 3),
        ElementsAre(-1, -3, -3, -3, 3, 3));
}

TEST(SlidingWindowMin, KEqualsOne) {
    EXPECT_THAT(
        slidingWindowMin({1, -2, 3, -4, 5, -6, 7, 8}, 1),
        ElementsAre(1, -2, 3, -4, 5, -6, 7, 8));
}

TEST(SlidingWindowMin, KEqualsArraySize) {
    EXPECT_THAT(slidingWindowMin({4, 2, 7, 1}, 4), ElementsAre(1));
}

TEST(SlidingWindowMin, TwoElementWindow) {
    EXPECT_THAT(
        slidingWindowMin({1, -2, 3, -4, 5, -6, 7, 8}, 2),
        ElementsAre(-2, -2, -4, -4, -6, -6, 7));
}

TEST(SlidingWindowMin, ThreeElementWindow) {
    EXPECT_THAT(
        slidingWindowMin({1, -2, 3, -4, 5, -6, 7, 8}, 3),
        ElementsAre(-2, -4, -4, -6, -6, -6));
}

TEST(SlidingWindowMin, IncreasingSequence) {
    EXPECT_THAT(slidingWindowMin({1, 2, 3, 4, 5}, 2), ElementsAre(1, 2, 3, 4));
}

TEST(SlidingWindowMin, DecreasingSequence) {
    EXPECT_THAT(slidingWindowMin({5, 4, 3, 2, 1}, 2), ElementsAre(4, 3, 2, 1));
}

TEST(SlidingWindowMin, AllSameValues) {
    EXPECT_THAT(slidingWindowMin({7, 7, 7, 7}, 2), ElementsAre(7, 7, 7));
}

TEST(SlidingWindowMin, SingleElementArray) {
    EXPECT_THAT(slidingWindowMin({42}, 1), ElementsAre(42));
}

TEST(SlidingWindowMin, DuplicatesWithNewMinimumAtEnd) {
    EXPECT_THAT(slidingWindowMin({2, 2, 2, 1}, 3), ElementsAre(2, 1));
}

TEST(SlidingWindowMin, NegativeAndPositiveMix) {
    EXPECT_THAT(slidingWindowMin({-1, -3, 5, 3, 6, 7}, 3), ElementsAre(-3, -3, 3, 3));
}
