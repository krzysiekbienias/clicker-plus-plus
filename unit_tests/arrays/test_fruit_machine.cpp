#include "arrays/fruit_machine.hpp"
#include <gtest/gtest.h>

TEST(FruitMachine,HitTriple)
{
    std::array<std::vector<std::string>, 3> reels;
    std::array<unsigned, 3>       spins;

    reels[0] = {"Wild", "Star", "Bell", "Shell", "Seven", "Cherry", "Bar", "King", "Queen", "Jack"};
    reels[1] = {"Wild", "Star", "Bell", "Shell", "Seven", "Cherry", "Bar", "King", "Queen", "Jack"};
    reels[2] = {"Wild", "Star", "Bell", "Shell", "Seven", "Cherry", "Bar", "King", "Queen", "Jack"};
    spins    = {0, 0, 0};
    EXPECT_EQ(fruit(reels,spins),100);
}

TEST(FruitMachine,NoLuck)
{   std::array<std::vector<std::string>, 3> reels;
    std::array<unsigned, 3>       spins;
    reels[0] = {"Wild", "Star", "Bell", "Shell", "Seven", "Cherry", "Bar", "King", "Queen", "Jack"};
    reels[1] = {"Bar", "Wild", "Queen", "Bell", "King", "Seven", "Cherry", "Jack", "Star", "Shell"};
    reels[2] = {"Bell", "King", "Wild", "Bar", "Seven", "Jack", "Shell", "Cherry", "Queen", "Star"};
    spins    = {5, 4, 3};
    EXPECT_EQ(fruit(reels,spins),0);
}

TEST(FruitMachine,TwoWilds)
{   std::array<std::vector<std::string>, 3> reels;
    std::array<unsigned, 3>       spins;
    reels[0] = {"Wild", "Star", "Bell", "Shell", "Seven", "Cherry", "Bar", "King", "Queen", "Jack"};
    reels[1] = {"Wild", "Star", "Bell", "Shell", "Seven", "Cherry", "Bar", "King", "Queen", "Jack"};
    reels[2] = {"Wild", "Star", "Bell", "Shell", "Seven", "Cherry", "Bar", "King", "Queen", "Jack"};
    spins    = {0, 0, 1};
    EXPECT_EQ(fruit(reels,spins),10);
}


TEST(FruitMachine,TwoKings)
{   std::array<std::vector<std::string>, 3> reels;
    std::array<unsigned, 3>       spins;
    reels[0] = {"King", "Cherry", "Bar", "Jack", "Seven", "Queen", "Star", "Shell", "Bell", "Wild"};
    reels[1] = {"Bell", "Seven", "Jack", "Queen", "Bar", "Star", "Shell", "Wild", "Cherry", "King"};
    reels[2] = {"Wild", "King", "Queen", "Seven", "Star", "Bar", "Shell", "Cherry", "Jack", "Bell"};

    spins    = {0, 0, 1};
    EXPECT_EQ(fruit(reels,spins),3);
}