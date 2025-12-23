#include <gtest/gtest.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <greedy/assign_mice_to_holes.hpp>
using std::vector;

// Function under test:
// int miceToWholes(vector<int> &mice, vector<int> &holes);

static int Brute_MinMaxTime_ForSmall(const vector<int>& mice, const vector<int>& holes) {
    // Brute force all matchings by permuting holes.
    // Returns minimal possible maximum |mice[i] - assignedHole[i]|.
    int n = (int)mice.size();
    vector<int> h = holes;
    std::sort(h.begin(), h.end());

    vector<int> m = mice;
    std::sort(m.begin(), m.end()); // brute uses sorted mice just for determinism

    int best = INT_MAX;
    do {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur = std::max(cur, std::abs(m[i] - h[i]));
            if (cur >= best) break;
        }
        best = std::min(best, cur);
    } while (std::next_permutation(h.begin(), h.end()));
    return best;
}

TEST(MiceToHoles, SingleMouse_SamePosition) {
    vector<int> mice{5};
    vector<int> holes{5};
    EXPECT_EQ(miceToWholes(mice, holes), 0);
}

TEST(MiceToHoles, SingleMouse_DifferentPosition) {
    vector<int> mice{-3};
    vector<int> holes{10};
    EXPECT_EQ(miceToWholes(mice, holes), 13);
}

TEST(MiceToHoles, AlreadyAligned_NoMoves) {
    vector<int> mice{1, 2, 3};
    vector<int> holes{1, 2, 3};
    EXPECT_EQ(miceToWholes(mice, holes), 0);
}

TEST(MiceToHoles, NeedsReordering_UnsortedInputs) {
    vector<int> mice{4, 1, 9};
    vector<int> holes{10, 2, 5};
    // Optimal pairing after sorting: mice [1,4,9], holes [2,5,10] => max = 1
    EXPECT_EQ(miceToWholes(mice, holes), 1);
}

TEST(MiceToHoles, ManySpacesBetween_NotRelevant_ButDuplicatesAllowed) {
    // Duplicates in positions are allowed in arrays (same coordinate),
    // constraint is only "one mouse per hole".
    vector<int> mice{0, 0, 0};
    vector<int> holes{-1, 0, 1};
    // Sorted pairing => distances [1,0,1] => max = 1
    EXPECT_EQ(miceToWholes(mice, holes), 1);
}

TEST(MiceToHoles, NegativeAndPositiveCoordinates) {
    vector<int> mice{-10, -5, 0, 7};
    vector<int> holes{-6, -4, 2, 9};
    // Sorted pairing => abs diffs: 4,1,2,2 => max = 4
    EXPECT_EQ(miceToWholes(mice, holes), 4);
}

TEST(MiceToHoles, WideGap_OneMouseTravelDominates) {
    vector<int> mice{0, 1, 2};
    vector<int> holes{100, 101, 102};
    EXPECT_EQ(miceToWholes(mice, holes), 100);
}

TEST(MiceToHoles, SymmetricSwapWouldBeWorse) {
    // This catches wrong greedy like "match each mouse to nearest available hole" without global ordering.
    vector<int> mice{1, 2};
    vector<int> holes{0, 100};
    // Optimal is [1->0, 2->100] max=98 OR [1->100,2->0] max=99 => best 98
    EXPECT_EQ(miceToWholes(mice, holes), 98);
}

TEST(MiceToHoles, Small_BruteForceCrossCheck_N4) {
    vector<int> mice{8, -1, 3, 3};
    vector<int> holes{2, 9, -2, 4};
    int expected = Brute_MinMaxTime_ForSmall(mice, holes);
    EXPECT_EQ(miceToWholes(mice, holes), expected);
}

TEST(MiceToHoles, Small_BruteForceCrossCheck_N5) {
    vector<int> mice{5, 1, 9, -3, 2};
    vector<int> holes{0, 6, 10, -4, 3};
    int expected = Brute_MinMaxTime_ForSmall(mice, holes);
    EXPECT_EQ(miceToWholes(mice, holes), expected);
}

TEST(MiceToHoles, Medium_StabilityAndNotMutatingIsNotRequiredButResultMustMatch) {
    // If your implementation sorts in-place, that's fine.
    vector<int> mice{12, 3, 19, 7, -2, 0, 5, 5};
    vector<int> holes{6, 20, 4, -1, 13, 8, 0, 10};
    // Expected if sorted pairing:
    // mice  [-2,0,3,5,5,7,12,19]
    // holes [-1,0,4,6,8,10,13,20]
    // diffs [ 1,0,1,1,3,3, 1, 1] => max = 3
    EXPECT_EQ(miceToWholes(mice, holes), 3);
}

TEST(MiceToHoles, Large_MonotonicShiftedBlocks) {
    const int n = 1000;
    vector<int> mice;  mice.reserve(n);
    vector<int> holes; holes.reserve(n);

    // mice at 0..999, holes at 500..1499 => answer should be 500
    for (int i = 0; i < n; ++i) {
        mice.push_back(i);
        holes.push_back(i + 500);
    }
    EXPECT_EQ(miceToWholes(mice, holes), 500);
}

TEST(MiceToHoles, Large_ReversedOrderInputs) {
    const int n = 2000;
    vector<int> mice;  mice.reserve(n);
    vector<int> holes; holes.reserve(n);

    // Same set but in reverse/shuffled-ish order to ensure you sort correctly.
    for (int i = n - 1; i >= 0; --i) mice.push_back(i * 2);      // 0,2,4,... but reversed insertion
    for (int i = n - 1; i >= 0; --i) holes.push_back(i * 2 + 1); // 1,3,5,... reversed insertion

    // After sorting: mice 0..(2n-2), holes 1..(2n-1) => all diffs = 1
    EXPECT_EQ(miceToWholes(mice, holes), 1);
}
