#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "backtracking/permutations.hpp"
using ::testing::ElementsAre;

#include <backtracking/permutations.hpp>

namespace {
    std::vector<std::vector<int>>permutationsIdiomatic(std::vector<int> nums)
    {   std::vector<std::vector<int>>result;
        sort(nums.begin(),nums.end());
        do
        {
            result.emplace_back(nums);
        }while (std::next_permutation(nums.begin(),nums.end()));
    return result;

    }

    void sortPermutations(std::vector<std::vector<int>>& perms)
    {
        std::sort(perms.begin(), perms.end());
    }
}

TEST(Permutations,TrivalCase)
{
    std::vector<int> vec={1,2,3};
    std::vector<std::vector<int>>actual =permutations(vec);
    std::vector<std::vector<int>>expected={{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
    EXPECT_THAT(actual,expected);
}

TEST(Permutations, EmptyVector_ReturnsOneEmptyPermutation)
{
    std::vector<int> vec = {};

    auto actual = permutations(vec);
    auto expected = permutationsIdiomatic(vec);

    sortPermutations(actual);
    sortPermutations(expected);

    EXPECT_EQ(actual, expected);
}

TEST(Permutations, SingleElement)
{
    std::vector<int> vec = {42};

    auto actual = permutations(vec);
    auto expected = permutationsIdiomatic(vec);

    EXPECT_EQ(actual, expected);
}

TEST(Permutations, TwoElements)
{
    std::vector<int> vec = {7, 9};

    auto actual = permutations(vec);
    auto expected = permutationsIdiomatic(vec);

    sortPermutations(actual);
    sortPermutations(expected);

    EXPECT_EQ(actual, expected);
}

TEST(Permutations, InputNotSortedStillProducesAllPermutations)
{
    std::vector<int> vec = {3, 1, 2};

    auto actual = permutations(vec);
    auto expected = permutationsIdiomatic(vec);

    sortPermutations(actual);
    sortPermutations(expected);

    EXPECT_EQ(actual, expected);
}

TEST(Permutations, ContainsNegativeNumbers)
{
    std::vector<int> vec = {-1, 0, 2};

    auto actual = permutations(vec);
    auto expected = permutationsIdiomatic(vec);

    sortPermutations(actual);
    sortPermutations(expected);

    EXPECT_EQ(actual, expected);
}

TEST(Permutations, FourElements_CountMatches24)
{
    std::vector<int> vec = {1, 2, 3, 4};

    auto actual = permutations(vec);
    EXPECT_EQ(actual.size(), 24u);

    // Also verify exact set vs oracle.
    auto expected = permutationsIdiomatic(vec);
    sortPermutations(actual);
    sortPermutations(expected);

    EXPECT_EQ(actual, expected);
}

TEST(Permutations, NoDuplicatesInResult_ForDistinctInput)
{
    std::vector<int> vec = {10, 20, 30};

    auto actual = permutations(vec);

    // Make a copy, sort, then check adjacent duplicates.
    sortPermutations(actual);

    bool hasDup = false;
    for (size_t i = 1; i < actual.size(); ++i) {
        if (actual[i] == actual[i - 1]) {
            hasDup = true;
            break;
        }
    }
    EXPECT_FALSE(hasDup);
}