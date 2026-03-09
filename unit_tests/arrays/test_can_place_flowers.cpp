#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "arrays/can_place_flowers.hpp"

TEST(CanPlaceFlowers,TrivalCase){
    std::vector<int>  flowerPod={1,0,0,0,1};
    int flowersToSeed=1;
    EXPECT_TRUE(canPlaceFlowers(flowerPod,flowersToSeed));
}

TEST(CanPlaceFlowers,TrivalCaseNotPossible){
    std::vector<int>  flowerPod={1,0,0,0,1};
    int flowersToSeed=2;
    EXPECT_FALSE(canPlaceFlowers(flowerPod,flowersToSeed));
}

TEST(CanPlaceFlowers, EmptyRequestAlwaysPossible) {
    std::vector<int> flowerBed{1, 0, 0, 0, 1};
    int flowersToSeed = 0;
    EXPECT_TRUE(canPlaceFlowers(flowerBed, flowersToSeed));
}

TEST(CanPlaceFlowers, SingleEmptyPlotCanPlaceOne) {
    std::vector<int> flowerBed{0};
    int flowersToSeed = 1;
    EXPECT_TRUE(canPlaceFlowers(flowerBed, flowersToSeed));
}

TEST(CanPlaceFlowers, SingleOccupiedPlotCannotPlaceOne) {
    std::vector<int> flowerBed{1};
    int flowersToSeed = 1;
    EXPECT_FALSE(canPlaceFlowers(flowerBed, flowersToSeed));
}

TEST(CanPlaceFlowers, TwoEmptyPlotsCanPlaceOne) {
    std::vector<int> flowerBed{0, 0};
    int flowersToSeed = 1;
    EXPECT_TRUE(canPlaceFlowers(flowerBed, flowersToSeed));
}

TEST(CanPlaceFlowers, TwoEmptyPlotsCannotPlaceTwo) {
    std::vector<int> flowerBed{0, 0};
    int flowersToSeed = 2;
    EXPECT_FALSE(canPlaceFlowers(flowerBed, flowersToSeed));
}

TEST(CanPlaceFlowers, AllEmptyOddSizedBed) {
    std::vector<int> flowerBed{0, 0, 0, 0, 0};
    int flowersToSeed = 3;
    EXPECT_TRUE(canPlaceFlowers(flowerBed, flowersToSeed));
}

TEST(CanPlaceFlowers, AllEmptyOddSizedBedTooManyFlowers) {
    std::vector<int> flowerBed{0, 0, 0, 0, 0};
    int flowersToSeed = 4;
    EXPECT_FALSE(canPlaceFlowers(flowerBed, flowersToSeed));
}

TEST(CanPlaceFlowers, AllEmptyEvenSizedBed) {
    std::vector<int> flowerBed{0, 0, 0, 0};
    int flowersToSeed = 2;
    EXPECT_TRUE(canPlaceFlowers(flowerBed, flowersToSeed));
}

TEST(CanPlaceFlowers, StartOfBedAvailable) {
    std::vector<int> flowerBed{0, 0, 1, 0, 1};
    int flowersToSeed = 1;
    EXPECT_TRUE(canPlaceFlowers(flowerBed, flowersToSeed));
}

TEST(CanPlaceFlowers, EndOfBedAvailable) {
    std::vector<int> flowerBed{1, 0, 1, 0, 0};
    int flowersToSeed = 1;
    EXPECT_TRUE(canPlaceFlowers(flowerBed, flowersToSeed));
}

TEST(CanPlaceFlowers, MiddlePlotAvailable) {
    std::vector<int> flowerBed{1, 0, 0, 0, 1};
    int flowersToSeed = 1;
    EXPECT_TRUE(canPlaceFlowers(flowerBed, flowersToSeed));
}

TEST(CanPlaceFlowers, NoSpaceBecauseOfAdjacencyRules) {
    std::vector<int> flowerBed{1, 0, 1, 0, 1};
    int flowersToSeed = 1;
    EXPECT_FALSE(canPlaceFlowers(flowerBed, flowersToSeed));
}

TEST(CanPlaceFlowers, MultiplePlacementsPossible) {
    std::vector<int> flowerBed{0, 0, 1, 0, 0, 0, 1, 0, 0};
    int flowersToSeed = 3;
    EXPECT_TRUE(canPlaceFlowers(flowerBed, flowersToSeed));
}

TEST(CanPlaceFlowers, MultiplePlacementsNotPossible) {
    std::vector<int> flowerBed{0, 0, 1, 0, 0, 0, 1, 0, 0};
    int flowersToSeed = 4;
    EXPECT_FALSE(canPlaceFlowers(flowerBed, flowersToSeed));
}

TEST(CanPlaceFlowers, AlreadyFullBedCannotPlaceAny) {
    std::vector<int> flowerBed{1, 0, 1, 0, 1, 0, 1};
    int flowersToSeed = 1;
    EXPECT_FALSE(canPlaceFlowers(flowerBed, flowersToSeed));
}