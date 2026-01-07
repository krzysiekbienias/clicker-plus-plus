#include <gtest/gtest.h>

#include <algorithm>
#include <climits>
#include <random>
#include <unordered_set>
#include <vector>
#include <arrays/first_missing_positive.hpp>

// ---------- Test-only oracle (brute force, safe but slower) ----------
static int BruteFirstMissingPositive(const std::vector<int>& nums) {
    std::unordered_set<int> s;
    s.reserve(nums.size() * 2 + 1);
    for (int x : nums) {
        if (x > 0) s.insert(x);
    }
    int need = 1;
    while (s.count(need)) ++need;
    return need;
}

// ---------- Helpers ----------
static std::vector<int> MakeRange(int lo, int hi) { // inclusive
    std::vector<int> v;
    if (hi < lo) return v;
    v.reserve(static_cast<size_t>(hi - lo + 1));
    for (int x = lo; x <= hi; ++x) v.push_back(x);
    return v;
}

static void Shuffle(std::vector<int>& v, uint32_t seed) {
    std::mt19937 rng(seed);
    std::shuffle(v.begin(), v.end(), rng);
}

// ====================================================================
//                         Deterministic tests
// ====================================================================

TEST(FirstMissingPositive, EmptyVector) {
    std::vector<int> nums;
    EXPECT_EQ(firstMissingPositive(nums), 1);
}

TEST(FirstMissingPositive, SingleElement) {
    std::vector<int> a{1};
    EXPECT_EQ(firstMissingPositive(a), 2);

    std::vector<int> b{2};
    EXPECT_EQ(firstMissingPositive(b), 1);

    std::vector<int> c{0};
    EXPECT_EQ(firstMissingPositive(c), 1);

    std::vector<int> d{-1};
    EXPECT_EQ(firstMissingPositive(d), 1);
}

TEST(FirstMissingPositive, AllNonPositive) {
    std::vector<int> nums{0, -1, -2, -3, INT_MIN};
    EXPECT_EQ(firstMissingPositive(nums), 1);
}

TEST(FirstMissingPositive, BasicExamples) {
    std::vector<int> a{3, 4, -1, 1};
    EXPECT_EQ(firstMissingPositive(a), 2);

    std::vector<int> b{1, 2, 0};
    EXPECT_EQ(firstMissingPositive(b), 3);

    std::vector<int> c{7, 8, 9, 11, 12};
    EXPECT_EQ(firstMissingPositive(c), 1);
}

TEST(FirstMissingPositive, Duplicates) {
    std::vector<int> a{1, 1};
    EXPECT_EQ(firstMissingPositive(a), 2);

    std::vector<int> b{2, 2, 2};
    EXPECT_EQ(firstMissingPositive(b), 1);

    std::vector<int> c{1, 2, 2, 3, 3};
    EXPECT_EQ(firstMissingPositive(c), 4);

    std::vector<int> d{1, 2, 3, 3, 4, 4, 5, 5};
    EXPECT_EQ(firstMissingPositive(d), 6);
}

TEST(FirstMissingPositive, AlreadyPerfectPrefix) {
    // if array contains 1..n => answer n+1
    std::vector<int> nums{1, 2, 3, 4, 5};
    EXPECT_EQ(firstMissingPositive(nums), 6);
}

TEST(FirstMissingPositive, MissingOne) {
    std::vector<int> nums{2, 3, 4};
    EXPECT_EQ(firstMissingPositive(nums), 1);
}

TEST(FirstMissingPositive, MissingInTheMiddle) {
    std::vector<int> nums{1, 2, 4, 5, 6};
    EXPECT_EQ(firstMissingPositive(nums), 3);
}

TEST(FirstMissingPositive, ContainsHugeValuesAndExtremes) {
    std::vector<int> nums{INT_MAX, INT_MIN, 1, 2, 3, 1000000000};
    EXPECT_EQ(firstMissingPositive(nums), 4);
}

TEST(FirstMissingPositive, LotsOfZeros) {
    std::vector<int> nums{0, 0, 0, 0, 0};
    EXPECT_EQ(firstMissingPositive(nums), 1);
}

TEST(FirstMissingPositive, MixedMessyInput) {
    std::vector<int> nums{10, -10, 1, 3, 3, 2, 0, -1, 5, 6, 6, 7, 100};
    EXPECT_EQ(firstMissingPositive(nums), 4);
}

TEST(FirstMissingPositive, VerySmallSize2And3CornerCases) {
    std::vector<int> a{1, 2};
    EXPECT_EQ(firstMissingPositive(a), 3);

    std::vector<int> b{2, 1};
    EXPECT_EQ(firstMissingPositive(b), 3);

    std::vector<int> c{2, 3};
    EXPECT_EQ(firstMissingPositive(c), 1);

    std::vector<int> d{1, 3};
    EXPECT_EQ(firstMissingPositive(d), 2);

    std::vector<int> e{3, 4, 1};
    EXPECT_EQ(firstMissingPositive(e), 2);
}

// ====================================================================
//                      Medium / larger deterministic
// ====================================================================

TEST(FirstMissingPositive, Medium_ShuffledRangeMissingOne) {
    // Build 1..5000 but remove 1337, shuffle.
    std::vector<int> nums = MakeRange(1, 5000);
    nums.erase(nums.begin() + 1337 - 1); // remove value 1337
    Shuffle(nums, 123);

    EXPECT_EQ(firstMissingPositive(nums), 1337);
}

TEST(FirstMissingPositive, Medium_ShuffledRangeWithNoise) {
    // 1..3000 but remove 1, add lots of negatives/zeros/duplicates
    std::vector<int> nums = MakeRange(1, 3000);
    nums.erase(nums.begin()); // remove 1
    for (int i = 0; i < 1000; ++i) nums.push_back(0);
    for (int i = 1; i <= 1000; ++i) nums.push_back(-i);
    for (int i = 0; i < 200; ++i) nums.push_back(2); // duplicates
    Shuffle(nums, 999);

    EXPECT_EQ(firstMissingPositive(nums), 1);
}

TEST(FirstMissingPositive, Large_PerfectPrefixThenNoise) {
    // Contains 1..20000 => answer is 20001 even with extra garbage
    std::vector<int> nums = MakeRange(1, 20000);
    for (int i = 0; i < 5000; ++i) nums.push_back(-1000000 - i);
    for (int i = 0; i < 5000; ++i) nums.push_back(0);
    for (int i = 0; i < 2000; ++i) nums.push_back(INT_MAX);
    Shuffle(nums, 42);

    EXPECT_EQ(firstMissingPositive(nums), 20001);
}

// ====================================================================
//                    Randomized property-based tests
//        (compares your solution vs brute-force oracle)
// ====================================================================

TEST(FirstMissingPositive, RandomSmall_AgainstBrute_1kTrials) {
    std::mt19937 rng(20260107);
    std::uniform_int_distribution<int> nDist(0, 50);
    std::uniform_int_distribution<int> valDist(-30, 60);

    for (int tc = 0; tc < 1000; ++tc) {
        int n = nDist(rng);
        std::vector<int> nums;
        nums.reserve(static_cast<size_t>(n));
        for (int i = 0; i < n; ++i) nums.push_back(valDist(rng));

        std::vector<int> copy = nums;
        int expected = BruteFirstMissingPositive(copy);

        int got = firstMissingPositive(nums); // your function may mutate nums
        ASSERT_EQ(got, expected) << "Failed on tc=" << tc << " n=" << n;
    }
}

TEST(FirstMissingPositive, RandomMedium_AgainstBrute_200Trials) {
    std::mt19937 rng(777);
    std::uniform_int_distribution<int> nDist(200, 800);
    std::uniform_int_distribution<int> valDist(-500, 1200);

    for (int tc = 0; tc < 200; ++tc) {
        int n = nDist(rng);
        std::vector<int> nums;
        nums.reserve(static_cast<size_t>(n));
        for (int i = 0; i < n; ++i) nums.push_back(valDist(rng));

        int expected = BruteFirstMissingPositive(nums);

        std::vector<int> work = nums;
        int got = firstMissingPositive(work);
        ASSERT_EQ(got, expected) << "Failed on tc=" << tc << " n=" << n;
    }
}

TEST(FirstMissingPositive, RandomStress_NoCrashAndReasonableRange) {
    // This test doesn't use brute (too big). It checks basic invariants:
    // result must be >=1 and <= n+1 (classic bound).
    std::mt19937 rng(123456);
    std::uniform_int_distribution<int> nDist(50000, 120000);
    std::uniform_int_distribution<int> valDist(INT_MIN, INT_MAX);

    int n = nDist(rng);
    std::vector<int> nums;
    nums.reserve(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) nums.push_back(valDist(rng));

    int got = firstMissingPositive(nums);
    EXPECT_GE(got, 1);
    EXPECT_LE(got, n + 1);
}
