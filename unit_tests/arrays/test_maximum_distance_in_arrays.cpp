#include "arrays/maximum_distance_in_arrays.hpp"
#include <gtest/gtest.h>

TEST(MaximumDistanceInArrays, BasicExample) {
    std::vector<std::vector<int>> arrays = {{1, 2, 3}, {4, 5}, {1, 2, 3}};
    EXPECT_EQ(maxDistance(arrays), 4);
}

TEST(MaximumDistanceInArrays, TwoArrays) {
    std::vector<std::vector<int>> arrays = {{1, 8}, {3, 6}};
    EXPECT_EQ(maxDistance(arrays), 5);
}

TEST(MaximumDistanceInArrays, MaxNotFromSameArray) {
    std::vector<std::vector<int>> arrays = {{1, 8}, {2, 9}};
    // 8 i 9 sa z roznych tablic, 9-1=8 jest najlepsze
    EXPECT_EQ(maxDistance(arrays), 8);
}

TEST(MaximumDistanceInArrays, NegativeNumbers) {
    std::vector<std::vector<int>> arrays = {{-5, -1}, {2, 4}};
    EXPECT_EQ(maxDistance(arrays), 9);
}

TEST(MaximumDistanceInArrays, SingleElementArrays) {
    std::vector<std::vector<int>> arrays = {{3}, {1}, {7}};
    EXPECT_EQ(maxDistance(arrays), 6);
}

TEST(MaximumDistanceInArrays, ManyArrays) {
    std::vector<std::vector<int>> arrays = {{1, 2, 3}, {4, 5}, {1, 2, 3}, {0, 10}};
    EXPECT_EQ(maxDistance(arrays), 10);
}
