#include <gtest/gtest.h>
#include <vector>
#include <random>
#include <algorithm>
#include <greedy/jump_to_the_end.hpp>
using std::vector;

// Expected function signature in your solution:
// bool jumpToTheEnd(const std::vector<int>& nums);


// ------------------------
// Small / basic correctness
// ------------------------

TEST(JumpGame, EmptyArray_DefineAsAlreadyAtEnd) {
    // Many platforms define empty as "already at end" (no move needed).
    // If you choose different convention, adjust expected value accordingly.
    EXPECT_TRUE(jumpToTheEnd({}));
}

TEST(JumpGame, SingleElement_AlwaysReachable) {
    EXPECT_TRUE(jumpToTheEnd({0}));
    EXPECT_TRUE(jumpToTheEnd({5}));
}

TEST(JumpGame, TwoElements) {
    EXPECT_TRUE(jumpToTheEnd({1, 0}));
    EXPECT_FALSE(jumpToTheEnd({0, 0}));
    EXPECT_TRUE(jumpToTheEnd({2, 0}));
}

TEST(JumpGame, SimpleReachableExamples) {
    EXPECT_TRUE(jumpToTheEnd({2, 3, 1, 1, 4}));
    EXPECT_TRUE(jumpToTheEnd({1, 1, 1, 1}));
    EXPECT_TRUE(jumpToTheEnd({3, 0, 0, 0}));
}

TEST(JumpGame, SimpleUnreachableExamples) {
    EXPECT_FALSE(jumpToTheEnd({3, 2, 1, 0, 4}));
    EXPECT_FALSE(jumpToTheEnd({1, 0, 1}));
    EXPECT_FALSE(jumpToTheEnd({2, 0, 0, 0, 1}));
}

TEST(JumpGame, ZerosAndTraps) {
    EXPECT_TRUE(jumpToTheEnd({2, 0, 2, 0, 1}));
    EXPECT_FALSE(jumpToTheEnd({1, 0, 0}));
    EXPECT_TRUE(jumpToTheEnd({4, 0, 0, 0, 0}));
    EXPECT_FALSE(jumpToTheEnd({1, 1, 0, 1}));
}

TEST(JumpGame, ExactLandingOnLastIndex) {
    EXPECT_TRUE(jumpToTheEnd({2, 0, 0}));     // 0 -> 2
    EXPECT_TRUE(jumpToTheEnd({1, 2, 0, 0}));  // 0->1->3
    EXPECT_FALSE(jumpToTheEnd({1, 1, 0, 0})); // stuck at index 2
}

TEST(JumpGame, BigJumpFromStart) {
    EXPECT_TRUE(jumpToTheEnd({100, 0, 0, 0, 0, 0}));
    EXPECT_TRUE(jumpToTheEnd({5, 0, 0, 0, 0}));
}

TEST(JumpGame, NeedsSkippingOverZeroIsland) {
    EXPECT_TRUE(jumpToTheEnd({2, 0, 1}));
    EXPECT_TRUE(jumpToTheEnd({3, 0, 0, 1, 0}));
    EXPECT_FALSE(jumpToTheEnd({2, 0, 0, 1}));
}

// ------------------------
// Medium edge cases
// ------------------------

TEST(JumpGame, LongAllOnes) {
    vector<int> a(50, 1);
    EXPECT_TRUE(jumpToTheEnd(a));
}

TEST(JumpGame, LongAllZeros) {
    vector<int> a(50, 0);
    // only reachable if size <= 1; here size=50
    EXPECT_FALSE(jumpToTheEnd(a));
}

TEST(JumpGame, IncreasingJumps) {
    // Should be reachable: reach keeps expanding
    EXPECT_TRUE(jumpToTheEnd({1, 2, 3, 4, 5, 6, 7, 8}));
}

TEST(JumpGame, DecreasingJumps_WithTrapAtEnd) {
    // Common pitfall: looks strong early but can still get stuck near the end
    EXPECT_FALSE(jumpToTheEnd({5, 4, 3, 2, 1, 0, 0}));
}

TEST(JumpGame, ReachableDespiteManyZeros) {
    EXPECT_TRUE(jumpToTheEnd({6, 0, 0, 0, 0, 0, 1}));


    EXPECT_FALSE(jumpToTheEnd({2, 0, 0, 0}));
}

// ------------------------
// Defensive / robustness (if you want to handle invalid input)
// ------------------------

TEST(JumpGame, NegativeValues_TreatedAsNoProgressOrInvalid) {
    // Problem usually states non-negative integers.
    // This test is here to "challenge" robustness: pick a policy.
    // Option A: treat negatives as 0 (no jump).
    // Option B: throw.
    // If you choose to throw, replace EXPECT_* accordingly.
    EXPECT_FALSE(jumpToTheEnd({1, -1, 1}));
}

// ------------------------
// Large / stress tests
// ------------------------

TEST(JumpGame, LargeReachable_Linear) {
    vector<int> a(200000, 1);
    EXPECT_TRUE(jumpToTheEnd(a));
}

TEST(JumpGame, LargeUnreachable_StuckNearEnd) {
    vector<int> a(200000, 1);
    a[a.size() - 2] = 0; // second last becomes trap: you can reach it but cannot jump to last
    EXPECT_FALSE(jumpToTheEnd(a));
}

TEST(JumpGame, LargeReachable_WithEarlyHugeJump) {
    vector<int> a(200000, 0);
    a[0] = 199999; // jump directly to last
    EXPECT_TRUE(jumpToTheEnd(a));
}

// ------------------------
// Randomized regression (deterministic seed)
// These compare against a simple reference implemented in-test
// ------------------------

static bool referencejumpToTheEnd(const vector<int>& nums) {
    // Greedy reference (standard). Keep here only for test oracle.
    // If you prefer not to have any "solution-like" logic in tests, delete these tests.
    long long far = 0;
    for (long long i = 0; i < (long long)nums.size(); ++i) {
        if (i > far) return false;
        far = std::max(far, i + (long long)std::max(nums[(size_t)i], 0));
        if (far >= (long long)nums.size() - 1) return true;
    }
    return nums.size() <= 1;
}

TEST(JumpGame, RandomSmall_CompareWithReference) {
    std::mt19937 rng(123456);
    std::uniform_int_distribution<int> nDist(0, 60);
    std::uniform_int_distribution<int> vDist(0, 10);

    for (int tc = 0; tc < 500; ++tc) {
        int n = nDist(rng);
        vector<int> a(n);
        for (int i = 0; i < n; ++i) a[i] = vDist(rng);
        EXPECT_EQ(jumpToTheEnd(a), referencejumpToTheEnd(a)) << "Failed on random case n=" << n;
    }
}

TEST(JumpGame, RandomMedium_CompareWithReference) {
    std::mt19937 rng(999);
    std::uniform_int_distribution<int> nDist(100, 400);
    std::uniform_int_distribution<int> vDist(0, 25);

    for (int tc = 0; tc < 200; ++tc) {
        int n = nDist(rng);
        vector<int> a(n);
        for (int i = 0; i < n; ++i) a[i] = vDist(rng);
        EXPECT_EQ(jumpToTheEnd(a), referencejumpToTheEnd(a)) << "Failed on random case n=" << n;
    }
}