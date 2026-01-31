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