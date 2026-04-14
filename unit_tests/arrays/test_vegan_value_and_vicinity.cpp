#include "arrays/vegan_value_and_vicinity.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Test Case 1: Basic filtering and sorting by rating then ID
TEST(FilterRestaurantsTest, BasicFilteringAndSorting) {
    // restaurants[i] = [id, rating, veganFriendly, price, distance]
    std::vector<std::vector<int>> restaurants = {
        {1, 4, 1, 40, 10},
        {2, 8, 0, 50, 5},
        {3, 8, 1, 30, 4},
        {4, 10, 0, 10, 3},
        {5, 1, 1, 15, 1}
    };

    // veganFriendly = 1, maxPrice = 50, maxDistance = 10
    // Should include: 3 (rating 8), 1 (rating 4), 5 (rating 1)
    std::vector<int> expected = {3, 1, 5};
    std::vector<int> actual = filterRestaurants(restaurants, 1, 50, 10);

    EXPECT_EQ(actual, expected);
}

// Test Case 2: Sorting tie-break (when ratings are equal, sort by ID descending)
TEST(FilterRestaurantsTest, SortingTieBreak) {
    std::vector<std::vector<int>> restaurants = {
        {1, 4, 1, 20, 5},
        {2, 4, 1, 20, 5}, // Same rating as ID 1, but higher ID
        {3, 4, 1, 20, 5}  // Same rating, highest ID
    };

    std::vector<int> expected = {3, 2, 1};
    std::vector<int> actual = filterRestaurants(restaurants, 1, 100, 100);

    EXPECT_EQ(actual, expected);
}

// Test Case 3: Vegan Friendly filter disabled (veganFriendly = 0)
TEST(FilterRestaurantsTest, VeganFilterDisabled) {
    std::vector<std::vector<int>> restaurants = {
        {1, 4, 1, 20, 5},
        {2, 5, 0, 20, 5} // Not vegan, but filter is off
    };

    std::vector<int> expected = {2, 1};
    std::vector<int> actual = filterRestaurants(restaurants, 0, 100, 100);

    EXPECT_EQ(actual, expected);
}

// Test Case 4: Filtering by Max Price and Max Distance
TEST(FilterRestaurantsTest, PriceAndDistanceConstraints) {
    std::vector<std::vector<int>> restaurants = {
        {1, 5, 1, 100, 5}, // Too expensive
        {2, 5, 1, 10, 50}, // Too far
        {3, 5, 1, 10, 5}   // Just right
    };

    std::vector<int> expected = {3};
    std::vector<int> actual = filterRestaurants(restaurants, 1, 50, 10);

    EXPECT_EQ(actual, expected);
}

// Test Case 5: Empty result set
TEST(FilterRestaurantsTest, NoMatchingRestaurants) {
    std::vector<std::vector<int>> restaurants = {
        {1, 4, 1, 100, 100}
    };

    std::vector<int> expected = {};
    std::vector<int> actual = filterRestaurants(restaurants, 1, 10, 10);

    EXPECT_EQ(actual, expected);
}