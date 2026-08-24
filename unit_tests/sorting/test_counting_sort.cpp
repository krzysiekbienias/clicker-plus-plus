#include "sorting/counting_sort.hpp"
#include <gtest/gtest.h>

#include <vector>

using std::vector;

TEST(CountingSort, Empty) {
    EXPECT_EQ(countingSort({}, 0), (vector<int>{}));
}

TEST(CountingSort, SingleElement) {
    EXPECT_EQ(countingSort({0}, 0), (vector<int>{0}));
    EXPECT_EQ(countingSort({7}, 7), (vector<int>{7}));
}

TEST(CountingSort, AlreadySorted) {
    EXPECT_EQ(countingSort({1, 2, 3, 4}, 4), (vector<int>{1, 2, 3, 4}));
}

TEST(CountingSort, ReverseSorted) {
    EXPECT_EQ(countingSort({4, 3, 2, 1}, 4), (vector<int>{1, 2, 3, 4}));
}

TEST(CountingSort, WithDuplicates) {
    EXPECT_EQ(countingSort({3, 1, 2, 1, 3}, 3), (vector<int>{1, 1, 2, 3, 3}));
}

TEST(CountingSort, AllZeros) {
    EXPECT_EQ(countingSort({0, 0, 0}, 0), (vector<int>{0, 0, 0}));
}

TEST(CountingSort, AllSame) {
    EXPECT_EQ(countingSort({5, 5, 5, 5}, 5), (vector<int>{5, 5, 5, 5}));
}

TEST(CountingSort, IncludesZeroAndMax) {
    EXPECT_EQ(countingSort({0, 4, 1, 4, 0}, 4), (vector<int>{0, 0, 1, 4, 4}));
}

TEST(CountingSort, MaxValLargerThanActualMax) {
    EXPECT_EQ(countingSort({2, 0, 2}, 10), (vector<int>{0, 2, 2}));
}

TEST(CountingSort, ClassicExample) {
    EXPECT_EQ(countingSort({4, 2, 2, 8, 3, 3, 1}, 8),
              (vector<int>{1, 2, 2, 3, 3, 4, 8}));
}

TEST(CountingSort, StableRelativeOrderOfDuplicates) {
    EXPECT_EQ(countingSort({2, 1, 2}, 2), (vector<int>{1, 2, 2}));
}
