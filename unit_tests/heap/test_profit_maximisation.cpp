#include "heap/profit_maximisation.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <limits>

using std::vector;

// ---------- helpers (kept inside tests) ----------
static long long GreedyOracle_LL(vector<int> seats, int k) {
    // Max-heap greedy (always sell from currently largest row).
    std::make_heap(seats.begin(), seats.end());
    long long profit = 0;
    for (int i = 0; i < k; ++i) {
        if (seats.empty()) break;
        std::pop_heap(seats.begin(), seats.end());
        int top = seats.back();
        seats.pop_back();
        if (top <= 0) {
            // no vacant seats anywhere => all remaining tickets add 0
            break;
        }
        profit += top;
        --top;
        seats.push_back(top);
        std::push_heap(seats.begin(), seats.end());
    }
    return profit;
}

static long long BruteOracle_LL(vector<int> seats, int k) {
    // Exact max for small instances by exploring all choices.
    // State: multiset-like vector; try selling next ticket from any row with >0.
    // Complexity explodes, keep n small and k small in tests.
    std::sort(seats.begin(), seats.end(), std::greater<int>());

    struct KeyHash {
        size_t operator()(const std::pair<vector<int>, int>&) const { return 0; }
    };

    std::function<long long(vector<int>&, int)> dfs = [&](vector<int>& a, int kk) -> long long {
        if (kk == 0) return 0LL;
        long long best = 0;
        bool any = false;

        // Try each distinct row count once (avoid symmetric duplicates)
        for (int i = 0; i < (int)a.size(); ++i) {
            if (a[i] <= 0) continue;
            if (i > 0 && a[i] == a[i - 1]) continue; // same choice as previous
            any = true;

            a[i]--;
            // keep sorted desc with local fix
            int j = i;
            while (j + 1 < (int)a.size() && a[j] < a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                ++j;
            }
            long long cand = (long long)(a[j] + 1) + dfs(a, kk - 1); // (a[j]+1) was the value before decrement
            // undo: restore
            while (j > i) {
                std::swap(a[j], a[j - 1]);
                --j;
            }
            a[i]++;

            best = std::max(best, cand);
        }
        return any ? best : 0LL;
    };

    return dfs(seats, k);
}

static long long SumTopKFromSingleRow(long long x, long long k) {
    // x + (x-1) + ... for k terms, but not below 0
    long long t = std::min(x, k);
    // arithmetic series: t/2 * (2x - (t-1))
    return t * (2 * x - (t - 1)) / 2;
}

static void ExpectEqLongLongToInt(int got, long long expected) {
    ASSERT_GE(got, std::numeric_limits<int>::min());
    ASSERT_LE(got, std::numeric_limits<int>::max());
    EXPECT_EQ(got, (int)expected);
}

// TESTS


TEST(ProfitMaximisation, EmptySeats_ReturnsZero) {
    vector<int> seats{};
    EXPECT_EQ(profitMaximisation(seats, 5), 0);
}

TEST(ProfitMaximisation, KZero_ReturnsZero) {
    vector<int> seats{5, 1, 2};
    EXPECT_EQ(profitMaximisation(seats, 0), 0);
}

TEST(ProfitMaximisation, AllZeros_ReturnsZeroForAnyK) {
    vector<int> seats{0, 0, 0};
    EXPECT_EQ(profitMaximisation(seats, 1), 0);
    EXPECT_EQ(profitMaximisation(seats, 10), 0);
}

TEST(ProfitMaximisation, ContainsNegative_TreatedAsNonSellable_NoProfitFromThose) {
    // If your implementation clamps or allows negatives, this test will expose it.
    // Expected behavior for interview-style problems: rows with <=0 contribute nothing.
    vector<int> seats{-3, 2};
    // Best: sell 2 then 1 => profit 3
    ExpectEqLongLongToInt(profitMaximisation(seats, 2), 3LL);
    ExpectEqLongLongToInt(profitMaximisation(seats, 10), 3LL); // no seats after 2 sales
}

TEST(ProfitMaximisation, SingleRow_SmallK) {
    vector<int> seats{5};
    // 5 + 4 + 3 = 12
    ExpectEqLongLongToInt(profitMaximisation(seats, 3), 12LL);
}

TEST(ProfitMaximisation, SingleRow_KExceedsSeats_StopsAddingAfterZero) {
    vector<int> seats{3};
    // 3+2+1 + remaining zeros
    ExpectEqLongLongToInt(profitMaximisation(seats, 10), 6LL);
}

TEST(ProfitMaximisation, SampleLike_Simple) {
    vector<int> seats{2, 1, 1};
    // sell: 2,1,1 => 4
    ExpectEqLongLongToInt(profitMaximisation(seats, 3), 4LL);
}

TEST(ProfitMaximisation, GreedyMatters_NotJustSortOnce) {
    vector<int> seats{2, 2};
    // Optimal: 2+2+1 = 5 (pick both 2s first, then one 1)
    ExpectEqLongLongToInt(profitMaximisation(seats, 3), 5LL);
}

TEST(ProfitMaximisation, MultipleRows_Basic) {
    vector<int> seats{3, 1, 2};
    // sequence: 3,2,2,1 => 8
    ExpectEqLongLongToInt(profitMaximisation(seats, 4), 8LL);
}

TEST(ProfitMaximisation, KGreaterThanTotalSeats_TotalProfitIsSumOfArithmeticSeriesPerRow) {
    vector<int> seats{2, 3};
    // total capacity = 5, k=100 -> still only 2+1 + 3+2+1 = 9
    ExpectEqLongLongToInt(profitMaximisation(seats, 100), 9LL);
}

TEST(ProfitMaximisation, UnchangedByPermutationOfRows) {
    vector<int> a{5, 1, 4, 2};
    vector<int> b{2, 5, 1, 4};
    int k = 6;
    EXPECT_EQ(profitMaximisation(a, k), profitMaximisation(b, k));
}

TEST(ProfitMaximisation, BruteForceCrossCheck_TinyCases) {
    // Exhaustive oracle on small instances to catch subtle greedy/heap bugs.
    std::vector<std::vector<int>> cases = {
        {1},
        {2},
        {1,1},
        {2,1},
        {2,2},
        {3,1,1},
        {3,2,1},
        {4,1,1,1},
        {3,3,1}
    };
    for (const auto& seats : cases) {
        for (int k = 0; k <= 6; ++k) {
            long long expected = BruteOracle_LL(seats, k);
            int got = profitMaximisation(seats, k);
            ExpectEqLongLongToInt(got, expected);
        }
    }
}

TEST(ProfitMaximisation, RandomSmall_BruteForceCrossCheck) {
    std::mt19937 rng(123456);
    std::uniform_int_distribution<int> nDist(1, 5);
    std::uniform_int_distribution<int> seatDist(0, 5);
    std::uniform_int_distribution<int> kDist(0, 7);

    for (int tc = 0; tc < 200; ++tc) {
        int n = nDist(rng);
        vector<int> seats(n);
        for (int i = 0; i < n; ++i) seats[i] = seatDist(rng);
        int k = kDist(rng);

        long long expected = BruteOracle_LL(seats, k);
        int got = profitMaximisation(seats, k);
        ExpectEqLongLongToInt(got, expected);
    }
}

TEST(ProfitMaximisation, RandomMedium_GreedyOracleCrossCheck) {
    // Larger sizes where brute is too slow; compare against a separate greedy oracle.
    std::mt19937 rng(98765);
    std::uniform_int_distribution<int> nDist(10, 80);
    std::uniform_int_distribution<int> seatDist(0, 100);
    std::uniform_int_distribution<int> kDist(0, 2000);

    for (int tc = 0; tc < 80; ++tc) {
        int n = nDist(rng);
        vector<int> seats(n);
        for (int i = 0; i < n; ++i) seats[i] = seatDist(rng);
        int k = kDist(rng);

        long long expected = GreedyOracle_LL(seats, k);
        int got = profitMaximisation(seats, k);
        ExpectEqLongLongToInt(got, expected);
    }
}

TEST(ProfitMaximisation, Stress_LargeInput_JustSanity) {
    // Sanity for performance and overflow-ish behavior (still int return).
    // If your function uses long long internally, it should be fine.
    int n = 200000;
    vector<int> seats(n, 1000);
    int k = 200000; // one ticket per row, easy

    int got = profitMaximisation(seats, k);

    // Expected profit is 1000 repeated k times => 200000 * 1000 = 200,000,000
    // Fits in int.
    EXPECT_EQ(got, 200000000);
}

TEST(ProfitMaximisation, PotentialOverflow_ShouldUseWideAccumulatorInternally) {
    // This test is designed to fail if you sum in int and overflow.
    // Return type is int, so we keep expected within int range by limiting k.
    vector<int> seats{1000000000, 1000000000};
    int k = 2;
    // profit = 1e9 + 1e9 = 2e9 (fits in signed 32-bit? 2,000,000,000 < 2,147,483,647 yes)
    ExpectEqLongLongToInt(profitMaximisation(seats, k), 2000000000LL);
}

TEST(ProfitMaximisation, RowDepletesToZero_NeverGoesNegativeInPricing) {
    vector<int> seats{1};
    // Sell 1 ticket => profit 1, after that row has 0 seats => all remaining contribute 0.
    ExpectEqLongLongToInt(profitMaximisation(seats, 5), 1LL);
}
