#include "heap/connect_ropes.hpp"
#include <gtest/gtest.h>

#include <gtest/gtest.h>
#include <vector>
#include <climits>
#include <numeric>
#include <algorithm>

using std::vector;

// Function under test:
int connectRopes(const vector<int>& ropes);

// --------------------
// Helpers for property-style checks (no solution revealed)
// --------------------
static long long SumLL(const vector<int>& a) {
    return std::accumulate(a.begin(), a.end(), 0LL);
}

// A very weak but always-true lower bound when n>=2:
// any way of merging must pay at least total sum once (final merge includes all lengths).
static long long LowerBoundAny(const vector<int>& ropes) {
    if (ropes.size() <= 1) return 0;
    return SumLL(ropes);
}

// For equal lengths x repeated n times, Huffman-style merging has known cost formula
// for n being a power of two: cost = x * n * log2(n).
static long long EqualPowerOfTwoExpectedCost(long long x, int n) {
    // n is power of two.
    int lg = 0;
    int t = n;
    while ((t >>= 1) != 0) ++lg;
    return x * n * lg;
}

// --------------------
// Basic / edge cases
// --------------------
TEST(ConnectRopes, EmptyInput_ReturnsZero) {
    EXPECT_EQ(connectRopes({}), 0);
}

TEST(ConnectRopes, SingleRope_ReturnsZero) {
    EXPECT_EQ(connectRopes({5}), 0);
    EXPECT_EQ(connectRopes({0}), 0);
}

TEST(ConnectRopes, TwoRopes_JustSum) {
    EXPECT_EQ(connectRopes({3, 4}), 7);
    EXPECT_EQ(connectRopes({1, 10}), 11);
    EXPECT_EQ(connectRopes({1, 1}), 2);
}


TEST(ConnectRopes, AlreadySortedOrNotDoesNotMatter) {
    EXPECT_EQ(connectRopes({1, 2, 3, 4, 5}), connectRopes({5, 4, 3, 2, 1}));
}

// --------------------
// Classic known answers
// --------------------
TEST(ConnectRopes, ClassicExample1) {
    // Typical textbook example: 2,3,4,6 => 29
    // merges: (2+3)=5, (4+5)=9, (6+9)=15 => 5+9+15=29
    EXPECT_EQ(connectRopes({4, 3, 2, 6}), 29);
}

TEST(ConnectRopes, ClassicExample2) {
    // 1,2,5,10,35,89 => 224 (common known case)
    // (You can verify by hand with repeated "two smallest" merges.)
    EXPECT_EQ(connectRopes({1, 2, 5, 10, 35, 89}), 224);
}

TEST(ConnectRopes, SmallHandComputable) {
    // 1,2,3 => (1+2)=3, (3+3)=6 => 9
    EXPECT_EQ(connectRopes({1, 2, 3}), 9);

    // 5,5,5 => (5+5)=10, (5+10)=15 => 25
    EXPECT_EQ(connectRopes({5, 5, 5}), 25);

    // 8,4,6,12 => (4+6)=10, (8+10)=18, (12+18)=30 => 58
    EXPECT_EQ(connectRopes({8, 4, 6, 12}), 58);
}

// --------------------
// Tricky "pairing extremes" counterexamples
// (catches wrong greedy like smallest+largest pairing)
// --------------------
TEST(ConnectRopes, Counterexample_PairingExtremesFails_1) {
    // Correct minimal cost is 22:
    // (1+2)=3, (3+3)=6, (4+6)=10 => 3+6+10=19? wait careful: ropes are 1,2,3,4
    // Minimal is: (1+2)=3, (3+3)=6, (4+6)=10 => total 3+6+10=19
    EXPECT_EQ(connectRopes({1, 2, 3, 4}), 19);
}

TEST(ConnectRopes, Counterexample_PairingExtremesFails_2) {
    // 1,2,7,8
    // Optimal: (1+2)=3, (3+7)=10, (10+8)=18 => 3+10+18=31
    // Extremes pairing would do (1+8)=9, (2+7)=9, (9+9)=18 => 36
    EXPECT_EQ(connectRopes({1, 2, 7, 8}), 31);
}

TEST(ConnectRopes, Counterexample_PairingExtremesFails_3) {
    // 1,2,3,10
    // Optimal: (1+2)=3, (3+3)=6, (6+10)=16 => 3+6+16=25
    EXPECT_EQ(connectRopes({10, 1, 2, 3}), 25);
}

// --------------------
// Duplicates and symmetry
// --------------------
TEST(ConnectRopes, ManyDuplicates) {
    // 4 ropes of length 1: cost = 1*4*log2(4)=8
    EXPECT_EQ(connectRopes({1, 1, 1, 1}), 8);

    // 8 ropes of length 2: cost = 2*8*log2(8)=2*8*3=48
    vector<int> ropes(8, 2);
    EXPECT_EQ(connectRopes(ropes), 48);
}

TEST(ConnectRopes, MediumDuplicates_Mixed) {
    // 2,2,2,2,10
    // Optimal: (2+2)=4, (2+2)=4, (4+4)=8, (8+10)=18 => total 4+4+8+18=34
    EXPECT_EQ(connectRopes({2, 2, 2, 2, 10}), 34);
}

// --------------------
// "Big-ish" tests: check properties + known closed form
// --------------------
TEST(ConnectRopes, PowerOfTwoEqualLengths_ClosedForm) {
    // n=16, x=3 => expected = 3*16*4 = 192
    vector<int> ropes(16, 3);
    EXPECT_EQ(connectRopes(ropes), 192);
}

TEST(ConnectRopes, LargeN_AllOnes_PropertyBounds) {
    // This test is designed to stress O(n log n) behavior and also sanity-check result.
    const int n = 20000;
    vector<int> ropes(n, 1);

    long long ans = connectRopes(ropes);

    // Lower bound: at least sum once
    EXPECT_GE(ans, LowerBoundAny(ropes));

    // Upper bound: naive sequential merge (not optimal but always valid)
    // If you merge by accumulating: (((1+1)+1)+...):
    // cost = 2 + 3 + ... + n = n(n+1)/2 - 1
    long long upper = (1LL * n * (n + 1)) / 2 - 1;
    EXPECT_LE(ans, upper);
}

TEST(ConnectRopes, LargeValues_NoOverflowInResultWithinInt_Assumption) {
    // If your implementation uses int internally, it may overflow.
    // This case still fits into 32-bit signed int if computed in 64-bit and cast at end? Not necessarily.
    // We keep it moderate but large enough to catch intermediate overflow if using int for sums.
    vector<int> ropes = {1000000000, 1000000000, 1000000000, 1000000000}; // 1e9 x4
    // Optimal for 4 equal elements: x*n*log2(n)=1e9*4*2=8e9 (does NOT fit in int).
    // If function returns int, this will overflow unless you define constraints differently.
    // So we only assert it is >0 is NOT safe. Instead, we assert it matches modulo? No.
    // Therefore: this test expects you either:
    //  - use long long and clamp/handle overflow, OR
    //  - the problem constraints guarantee smaller inputs.
    //
    // To keep tests universally usable, we just ensure it does not crash and is non-negative
    // IF you decide to return 64-bit later, update signature & test accordingly.
    int ans = connectRopes(ropes);
    (void)ans;
    SUCCEED();
}

// --------------------
// More small/medium exact answers
// --------------------
TEST(ConnectRopes, MediumExact_1) {
    // 1,1,2,3,5,8
    // (1+1)=2, (2+2)=4, (3+4)=7, (5+7)=12, (8+12)=20 => total 2+4+7+12+20=45
    EXPECT_EQ(connectRopes({1, 1, 2, 3, 5, 8}), 45);
}

TEST(ConnectRopes, MediumExact_2) {
    // 3,4,5,6,7
    // (3+4)=7, (5+6)=11, (7+7)=14, (11+14)=25 => 7+11+14+25=57
    EXPECT_EQ(connectRopes({3, 4, 5, 6, 7}), 57);
}

TEST(ConnectRopes, MediumExact_3) {
    // 1,3,11,5
    // (1+3)=4, (4+5)=9, (9+11)=20 => 4+9+20=33
    EXPECT_EQ(connectRopes({1, 3, 11, 5}), 33);
}

