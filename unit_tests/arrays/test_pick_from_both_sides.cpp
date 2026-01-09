#include <gtest/gtest.h>
#include <vector>
#include <limits>
#include <arrays/pick_from_both_sides.hpp>
using namespace std;

// Your function under test:
// int maxSumFromEnds(const vector<int>& arr, int b);

// -------------------------
// Small brute helper (only for tests)
// -------------------------
static int Brute_MaxSumFromEnds(const vector<int>& arr, int b) {
    const int n = (int)arr.size();
    if (b < 0 || b > n) return std::numeric_limits<int>::min(); // invalid
    int best = std::numeric_limits<int>::min();
    for (int left = 0; left <= b; ++left) {
        int right = b - left;
        long long sum = 0;
        for (int i = 0; i < left; ++i) sum += arr[i];
        for (int i = 0; i < right; ++i) sum += arr[n - 1 - i];
        if (sum > best) best = (int)sum;
    }
    return best;
}

// -------------------------
// Edge cases
// -------------------------
TEST(MaxSumFromEnds, EmptyArray_B0) {
    vector<int> a{};
    EXPECT_EQ(maxSumFromEnds(a, 0), 0);
}

TEST(MaxSumFromEnds, SingleElement_B0) {
    vector<int> a{7};
    EXPECT_EQ(maxSumFromEnds(a, 0), 0);
}

TEST(MaxSumFromEnds, SingleElement_B1) {
    vector<int> a{7};
    EXPECT_EQ(maxSumFromEnds(a, 1), 7);
}

TEST(MaxSumFromEnds, BEqualsN_AllTaken) {
    vector<int> a{1, 2, 3, 4};
    EXPECT_EQ(maxSumFromEnds(a, 4), 10);
}

TEST(MaxSumFromEnds, B0_ReturnZeroEvenIfNegatives) {
    vector<int> a{-5, -2, -100};
    EXPECT_EQ(maxSumFromEnds(a, 0), 0);
}

TEST(MaxSumFromEnds, AllNegative_PickLeastBad) {
    vector<int> a{-8, -1, -3, -4, -10};
    // best is to pick -8 (left) + -1 (left) = -9? but can mix ends:
    // b=2 -> candidates:
    // L2=-9, L1+R1=-8 + -10=-18, R2=-14 => best -9
    EXPECT_EQ(maxSumFromEnds(a, 2), -9);
}

TEST(MaxSumFromEnds, ContainsZeros) {
    vector<int> a{0, 0, 5, 0, 0};
    EXPECT_EQ(maxSumFromEnds(a, 2), 0);  // only ends are zeros
    EXPECT_EQ(maxSumFromEnds(a, 3), 0);  // still forced to take only ends, can't reach middle
}

TEST(MaxSumFromEnds, ClassicExample_MixIsBest) {
    vector<int> a{5, -2, 3, 1, 2};
    // b=3: take 5 (L) + 1? can't; valid combos:
    // L3=6, R3=6, L2+R1=3+2=5, L1+R2=5+3=8 => best 8
    EXPECT_EQ(maxSumFromEnds(a, 3), 8);
}

TEST(MaxSumFromEnds, PreferMostlyRight) {
    vector<int> a{1, 100, 3, 4, 5};
    // b=2: best is 5+4=9 (right two) vs 1+100=101? wait left two is 101 (bigger)
    EXPECT_EQ(maxSumFromEnds(a, 2), 101);
}

TEST(MaxSumFromEnds, PreferSplitNotAllOneSide) {
    vector<int> a{10, -100, 20, -100, 30};
    // b=2: candidates: L2=-90, R2=-70, L1+R1=10+30=40 => best 40
    EXPECT_EQ(maxSumFromEnds(a, 2), 40);
}

TEST(MaxSumFromEnds, ManySameValues_TiesOk) {
    vector<int> a{7, 7, 7, 7, 7};
    EXPECT_EQ(maxSumFromEnds(a, 3), 21);
}

TEST(MaxSumFromEnds, LargeMagnitudeWithinIntRange) {
    vector<int> a{1'000'000'000, -1'000'000'000, 1'000'000'000, -1'000'000'000};
    // b=2: best is pick 1e9 + (-1e9) from left = 0, or from right = 0, or split = 0
    EXPECT_EQ(maxSumFromEnds(a, 2), 0);
}

// -------------------------
// Small/medium deterministic with known answers
// -------------------------
TEST(MaxSumFromEnds, Small_B1_MaxOfEnds) {
    vector<int> a{4, 99, -7};
    EXPECT_EQ(maxSumFromEnds(a, 1), 4);  // ends are 4 and -7
}

TEST(MaxSumFromEnds, Small_B2) {
    vector<int> a{4, 99, -7};
    // b=2: L2=103, R2=92, split=4 + -7=-3 => best 103
    EXPECT_EQ(maxSumFromEnds(a, 2), 103);
}

TEST(MaxSumFromEnds, Medium_B4) {
    vector<int> a{1, 2, 3, 4, 5, 6, 1};
    // b=3 -> typical known answer 12? let's compute:
    // L3=6, R3=8, L2+R1=3+1=4, L1+R2=1+7=8 => best 8
    EXPECT_EQ(maxSumFromEnds(a, 3), 8);

    // b=4:
    // L4=10, R4=13 (6+5+? actually last 4: 6+5+4? wait array ends: [4,5,6,1] sum=16)
    // Let's brute-check expected via helper:
    EXPECT_EQ(maxSumFromEnds(a, 4), Brute_MaxSumFromEnds(a, 4));
}

TEST(MaxSumFromEnds, Medium_WithNegatives) {
    vector<int> a{-1, -2, 10, -3, 4, -5, 6};
    EXPECT_EQ(maxSumFromEnds(a, 3), Brute_MaxSumFromEnds(a, 3));
    EXPECT_EQ(maxSumFromEnds(a, 5), Brute_MaxSumFromEnds(a, 5));
}

// -------------------------
// Property-style tests (compare to brute force on many cases)
// -------------------------
TEST(MaxSumFromEnds, BruteCrossCheck_AllSubsetsSmallArrays) {
    // Deterministic pseudo-random-ish data without <random>
    vector<vector<int>> cases = {
        {1, 2, 3, 4},
        {5, -2, 3, 1, 2},
        {-3, -2, -1, -4},
        {9, 0, -1, 0, 9},
        {100, -100, 100, -100, 100},
        {2, 2, 2, 2, 2, 2},
        {8, -9, 10, -11, 12, -13, 14}
    };

    for (const auto& a : cases) {
        for (int b = 0; b <= (int)a.size(); ++b) {
            EXPECT_EQ(maxSumFromEnds(a, b), Brute_MaxSumFromEnds(a, b))
                << "n=" << a.size() << " b=" << b;
        }
    }
}

TEST(MaxSumFromEnds, BruteCrossCheck_ManySmallGenerated) {
    // Generate many arrays deterministically: values in [-10..10]
    for (int n = 0; n <= 9; ++n) {
        vector<int> a(n);
        for (int seed = 0; seed < 40; ++seed) {
            // fill
            for (int i = 0; i < n; ++i) {
                int v = (seed * 37 + i * 17 + 11) % 21; // 0..20
                a[i] = v - 10;                          // -10..10
            }
            for (int b = 0; b <= n; ++b) {
                EXPECT_EQ(maxSumFromEnds(a, b), Brute_MaxSumFromEnds(a, b))
                    << "n=" << n << " seed=" << seed << " b=" << b;
            }
        }
    }
}

// -------------------------
// Larger test (no brute; checks specific behavior / sanity)
// -------------------------
TEST(MaxSumFromEnds, LargeArray_Sanity_BHalf) {
    const int n = 10000;
    vector<int> a;
    a.reserve(n);
    for (int i = 0; i < n; ++i) {
        // mostly small numbers with occasional spikes near ends
        int v = (i * 1103515245u + 12345u) % 101; // 0..100
        v -= 50;                                  // -50..50
        a.push_back(v);
    }
    // Make ends very attractive
    a[0] = 1000;
    a[1] = 999;
    a[n-1] = 1000;
    a[n-2] = 999;

    int b = 2000;
    int ans = maxSumFromEnds(a, b);

    // Lower bound sanity: you can always take 2 best on each side + (b-4) other ends (could be negative),
    // but at least it must be >= sum of taking b from left OR b from right.
    long long leftSum = 0, rightSum = 0;
    for (int i = 0; i < b; ++i) leftSum += a[i];
    for (int i = 0; i < b; ++i) rightSum += a[n-1-i];

    EXPECT_GE(ans, (int)max(leftSum, rightSum));
}

// Optional: behavior for invalid b (comment out if your contract guarantees 0<=b<=n)
TEST(MaxSumFromEnds, InvalidB_GreaterThanN) {
    vector<int> a{1,2,3};
    // Define your expected behavior; here we just assert it doesn't crash and matches brute helper choice.
    EXPECT_EQ(maxSumFromEnds(a, 4), Brute_MaxSumFromEnds(a, 4));
}
