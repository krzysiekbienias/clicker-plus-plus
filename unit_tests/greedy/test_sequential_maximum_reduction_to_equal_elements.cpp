#include "greedy/sequential_maximum_reduction_to_equal_elements.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt

// 1) Already equal -> no operations
TEST(SequentialMaximumReductionToEqualElementsTest, AllElementsEqual) {
    std::vector<int> nums{5, 5, 5, 5};
    EXPECT_EQ(sequentialMaximumReductionToEqualElements(nums), 0);
}

// 2) Simple increasing distinct values
TEST(SequentialMaximumReductionToEqualElementsTest, AllDistinctSorted) {
    std::vector<int> nums{1, 2, 3};
    EXPECT_EQ(sequentialMaximumReductionToEqualElements(nums), 3);
}

// 3) Unsorted input should still work because function sorts internally
TEST(SequentialMaximumReductionToEqualElementsTest, UnsortedDistinctValues) {
    std::vector<int> nums{3, 1, 2};
    EXPECT_EQ(sequentialMaximumReductionToEqualElements(nums), 3);
}

// 4) Example with duplicates
TEST(SequentialMaximumReductionToEqualElementsTest, MixedDuplicates) {
    std::vector<int> nums{5, 1, 3};
    EXPECT_EQ(sequentialMaximumReductionToEqualElements(nums), 3);
}

// 5) Multiple duplicate groups
TEST(SequentialMaximumReductionToEqualElementsTest, SeveralGroupsOfDuplicates) {
    std::vector<int> nums{1, 1, 2, 2, 3};
    EXPECT_EQ(sequentialMaximumReductionToEqualElements(nums), 4);
}

// 6) Larger grouped example
TEST(SequentialMaximumReductionToEqualElementsTest, LargerGroupedInput) {
    std::vector<int> nums{4, 4, 4, 3, 3, 2};
    EXPECT_EQ(sequentialMaximumReductionToEqualElements(nums), 8);
}

// 7) Single element
TEST(SequentialMaximumReductionToEqualElementsTest, SingleElement) {
    std::vector<int> nums{42};
    EXPECT_EQ(sequentialMaximumReductionToEqualElements(nums), 0);
}

// 8) Two different elements
TEST(SequentialMaximumReductionToEqualElementsTest, TwoDifferentElements) {
    std::vector<int> nums{10, 20};
    EXPECT_EQ(sequentialMaximumReductionToEqualElements(nums), 1);
}


// 10) Many duplicates with one larger group above minimum
TEST(SequentialMaximumReductionToEqualElementsTest, DuplicatePlateaus) {
    std::vector<int> nums{1, 2, 2, 3, 3, 3};
    EXPECT_EQ(sequentialMaximumReductionToEqualElements(nums), 8);
}