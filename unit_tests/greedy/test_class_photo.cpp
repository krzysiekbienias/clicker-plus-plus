#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <greedy/class_photo.hpp>
using std::vector;

// Function under test:
// bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights);

TEST(ClassPhotos, SingleStudent_FalseIfEqualHeights) {
    EXPECT_FALSE(classPhotos({5}, {5}));
}


TEST(ClassPhotos, TwoStudents_SimpleTrue) {
    // One valid arrangement: back row strictly taller per position after ordering.
    EXPECT_TRUE(classPhotos({5, 8}, {6, 9}));
    EXPECT_TRUE(classPhotos({6, 9}, {5, 8}));
}

TEST(ClassPhotos, TwoStudents_FalseDueToEquality) {
    // Any pairing forces an equal comparison at some position.
    EXPECT_FALSE(classPhotos({5, 7}, {6, 7}));
}

TEST(ClassPhotos, AllEqualHeights_False) {
    EXPECT_FALSE(classPhotos({5, 5, 5}, {5, 5, 5}));
}

TEST(ClassPhotos, SameMultisetDifferentOrder_ShouldBeFalse) {
    // If both sets contain the same heights, strict inequality is impossible position-wise.
    EXPECT_FALSE(classPhotos({1, 2, 3, 4}, {4, 3, 2, 1}));
}

TEST(ClassPhotos, ProvidedLikeClassicExample_True) {
    // Typical scenario where one color can be entirely in the back.
    EXPECT_TRUE(classPhotos({5, 8, 1, 3, 4}, {6, 9, 2, 4, 5}));
}

TEST(ClassPhotos, ClassicFailure_InterleavingWouldBeNeededButNotAllowed) {
    // No matter which color is chosen for the back row, one position fails strictly.
    EXPECT_FALSE(classPhotos({6, 6, 6, 6}, {5, 6, 7, 8}));
}

TEST(ClassPhotos, MustBeStrictlyTaller_NotNonDecreasing) {
    // If implementation uses <= incorrectly, this should fail.
    EXPECT_FALSE(classPhotos({4, 5, 6}, {5, 6, 6}));
}

TEST(ClassPhotos, Duplicates_TrueWhenStrictlySeparated) {
    EXPECT_TRUE(classPhotos({2, 2, 2, 2}, {3, 3, 3, 3}));
    EXPECT_TRUE(classPhotos({3, 3, 3, 3}, {2, 2, 2, 2}));
}

TEST(ClassPhotos, Duplicates_FalseWhenAnyTieOccursAfterSorting) {
    EXPECT_FALSE(classPhotos({2, 2, 3, 3}, {2, 3, 3, 4})); // tie at smallest 2 vs 2
    EXPECT_FALSE(classPhotos({1, 1, 2, 2}, {1, 2, 2, 3})); // tie at smallest 1 vs 1
}

TEST(ClassPhotos, UnsortedInputs_ShouldStillWork) {
    EXPECT_TRUE(classPhotos({10, 1, 9, 2}, {11, 3, 12, 4}));
    EXPECT_FALSE(classPhotos({10, 1, 9, 2}, {9, 3, 12, 4})); // 10 vs 9 breaks if reds in front; other choice breaks elsewhere
}

TEST(ClassPhotos, DecideBackRowBySmallestElements_NotBySums) {
    // Red sum is larger, but red cannot be all in back due to the smallest comparison.
    // Correct logic should compare sorted positions strictly, not totals.
    EXPECT_FALSE(classPhotos({1, 100, 100}, {2, 3, 4}));
}

TEST(ClassPhotos, NegativeTest_PickWrongBackRowWouldFailButOtherWorks) {
    // If someone locks the back row choice incorrectly, they may return false.
    // Blue can be back: (6>5), (7>6), (8>7)
    EXPECT_TRUE(classPhotos({5, 6, 7}, {6, 7, 8}));
}

TEST(ClassPhotos, MediumSample_True) {
    EXPECT_TRUE(classPhotos(
        {140, 141, 150, 160, 170, 180},
        {141, 142, 151, 161, 171, 181}
    ));
}

TEST(ClassPhotos, MediumSample_FalseBecauseOnePairBreaks) {
    EXPECT_FALSE(classPhotos(
        {140, 141, 150, 160, 170, 180},
        {141, 142, 151, 159, 171, 181} // 160 vs 159 breaks if blue is front; other orientation breaks earlier
    ));
}

TEST(ClassPhotos, LargeMonotone_True) {
    const int n = 1000;
    vector<int> red(n), blue(n);
    for (int i = 0; i < n; ++i) {
        red[i] = 1000 + i;
        blue[i] = 2000 + i;
    }
    // Even with shuffled inputs, should remain true if logic sorts.
    std::mt19937 rng(123);
    std::shuffle(red.begin(), red.end(), rng);
    std::shuffle(blue.begin(), blue.end(), rng);

    EXPECT_TRUE(classPhotos(red, blue));
}

TEST(ClassPhotos, LargeWithSingleTie_False) {
    const int n = 500;
    vector<int> red(n), blue(n);
    for (int i = 0; i < n; ++i) {
        red[i] = 1000 + i;
        blue[i] = 2000 + i;
    }
    // Introduce a tie at one position after sorting:
    // Make smallest blue equal to smallest red.
    blue[0] = red[0];

    EXPECT_FALSE(classPhotos(red, blue));
}

TEST(ClassPhotos, Stress_RandomButConstructedTrue) {
    // Construct two arrays where blue is always +k taller per sorted position.
    const int n = 300;
    vector<int> base(n), red(n), blue(n);
    for (int i = 0; i < n; ++i) base[i] = 100 + (i % 50); // many duplicates
    std::mt19937 rng(42);
    std::shuffle(base.begin(), base.end(), rng);

    for (int i = 0; i < n; ++i) {
        red[i] = base[i];
        blue[i] = base[i] + 1;
    }
    std::shuffle(red.begin(), red.end(), rng);
    std::shuffle(blue.begin(), blue.end(), rng);

    EXPECT_TRUE(classPhotos(red, blue));
}

TEST(ClassPhotos, Stress_RandomWithGuaranteedImpossible) {
    // Same multiset -> impossible due to strictness.
    const int n = 300;
    vector<int> red(n), blue(n);
    for (int i = 0; i < n; ++i) red[i] = 100 + (i % 30);
    blue = red;

    std::mt19937 rng(99);
    std::shuffle(red.begin(), red.end(), rng);
    std::shuffle(blue.begin(), blue.end(), rng);

    EXPECT_FALSE(classPhotos(red, blue));
}