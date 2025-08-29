#include <gtest/gtest.h>
#include "stack/colliding_asteroids.hpp"

// Empty input
TEST(CollidingAsteroidsTest, EmptyInput) {
    std::vector<int> input{};
    std::vector<int> expected{};
    EXPECT_EQ(collidingAsteroids(input), expected);
}

// No collision: all moving right
TEST(CollidingAsteroidsTest, AllRightNoCollision) {
    std::vector<int> input{1, 2, 3};
    std::vector<int> expected{1, 2, 3};
    EXPECT_EQ(collidingAsteroids(input), expected);
}

// No collision: all moving left
TEST(CollidingAsteroidsTest, AllLeftNoCollision) {
    std::vector<int> input{-1, -2, -3};
    std::vector<int> expected{-1, -2, -3};
    EXPECT_EQ(collidingAsteroids(input), expected);
}

// Simple collision: one destroys the other
TEST(CollidingAsteroidsTest, SimpleCollisionOneSurvives) {
    std::vector<int> input{5, -3};
    std::vector<int> expected{5};
    EXPECT_EQ(collidingAsteroids(input), expected);
}

// Equal magnitude collision: both destroyed
TEST(CollidingAsteroidsTest, EqualMagnitudeBothDestroyed) {
    std::vector<int> input{4, -4};
    std::vector<int> expected{};
    EXPECT_EQ(collidingAsteroids(input), expected);
}

// Multiple collisions
TEST(CollidingAsteroidsTest, CascadingCollisions) {
    std::vector<int> input{10, 2, -5};
    std::vector<int> expected{10};
    EXPECT_EQ(collidingAsteroids(input), expected);
}

// Stress test with large input
TEST(CollidingAsteroidsTest, PerformanceLargeInput) {
    std::vector<int> input(50000, 1); // all right-going
    input.push_back(-999999); // one strong left-going
    std::vector<int> expected{-999999};
    EXPECT_EQ(collidingAsteroids(input), expected);
}
