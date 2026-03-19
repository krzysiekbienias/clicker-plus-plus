#include "arrays/ride_scheduling_under_capacity.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

TEST(CarPoolingTest, ReturnsTrueForSingleTripWithinCapacity) {
    std::vector<std::vector<int>> trips = {
        {2, 1, 5}
    };

    EXPECT_TRUE(carPooling(trips, 2));
}

TEST(CarPoolingTest, ReturnsFalseForSingleTripExceedingCapacity) {
    std::vector<std::vector<int>> trips = {
        {3, 2, 7}
    };

    EXPECT_FALSE(carPooling(trips, 2));
}

TEST(CarPoolingTest, ReturnsTrueWhenTripsDoNotOverlap) {
    std::vector<std::vector<int>> trips = {
        {2, 1, 5},
        {3, 5, 8}
    };

    EXPECT_TRUE(carPooling(trips, 3));
}

TEST(CarPoolingTest, ReturnsTrueWhenPassengersDropOffBeforePickupAtSameLocation) {
    std::vector<std::vector<int>> trips = {
        {2, 1, 5},
        {3, 5, 7}
    };

    EXPECT_TRUE(carPooling(trips, 3));
}

TEST(CarPoolingTest, ReturnsFalseWhenOverlappingTripsExceedCapacity) {
    std::vector<std::vector<int>> trips = {
        {2, 1, 5},
        {3, 3, 7}
    };

    EXPECT_FALSE(carPooling(trips, 4));
}

TEST(CarPoolingTest, ReturnsTrueWhenOverlappingTripsExactlyMatchCapacity) {
    std::vector<std::vector<int>> trips = {
        {2, 1, 5},
        {3, 3, 7}
    };

    EXPECT_TRUE(carPooling(trips, 5));
}

TEST(CarPoolingTest, ReturnsTrueForMultipleTripsWithValidCapacityTimeline) {
    std::vector<std::vector<int>> trips = {
        {3, 2, 7},
        {3, 7, 9},
        {2, 1, 5}
    };

    EXPECT_TRUE(carPooling(trips, 5));
}

TEST(CarPoolingTest, ReturnsFalseForMultipleTripsWithPeakOverflow) {
    std::vector<std::vector<int>> trips = {
        {2, 1, 5},
        {3, 3, 7},
        {2, 4, 6}
    };

    EXPECT_FALSE(carPooling(trips, 6));
}

TEST(CarPoolingTest, ReturnsTrueForEmptyTrips) {
    std::vector<std::vector<int>> trips = {};

    EXPECT_TRUE(carPooling(trips, 0));
    EXPECT_TRUE(carPooling(trips, 5));
}

TEST(CarPoolingTest, ReturnsTrueWhenCapacityIsNeverExceededAcrossManyEvents) {
    std::vector<std::vector<int>> trips = {
        {2, 0, 4},
        {1, 2, 5},
        {3, 5, 7},
        {1, 6, 8}
    };

    EXPECT_TRUE(carPooling(trips, 4));
}

TEST(CarPoolingTest, ReturnsFalseWhenCapacityExceededImmediatelyAtStart) {
    std::vector<std::vector<int>> trips = {
        {4, 0, 3},
        {2, 0, 2}
    };

    EXPECT_FALSE(carPooling(trips, 5));
}

TEST(CarPoolingTest, HandlesUnsortedInputTrips) {
    std::vector<std::vector<int>> trips = {
        {3, 5, 7},
        {2, 1, 5},
        {1, 3, 6}
    };

    EXPECT_FALSE(carPooling(trips, 3));
}

TEST(CarPoolingTest, HandlesSeveralPickupsAndDropoffsAtSameLocation) {
    std::vector<std::vector<int>> trips = {
        {3, 1, 4},
        {2, 4, 6},
        {1, 4, 5}
    };

    EXPECT_TRUE(carPooling(trips, 3));
}

TEST(CarPoolingTest, ReturnsFalseWhenSameLocationEventsCauseOverflowAfterDropoffsHandled) {
    std::vector<std::vector<int>> trips = {
        {3, 1, 4},
        {2, 4, 6},
        {2, 4, 5}
    };

    EXPECT_FALSE(carPooling(trips, 3));
}