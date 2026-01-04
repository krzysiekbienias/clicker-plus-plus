#include "numbers_theory/prime_sum.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;

TEST(PrimeSum,trival) {
    EXPECT_EQ(primeSum(10),(vector<int>{3,7}));
    EXPECT_EQ(primeSum(100),(vector<int>{3,97}));
    EXPECT_EQ(primeSum(4),(vector<int>{2,2}));
}




TEST(PrimeSum, Trivial_6) {
    EXPECT_EQ(primeSum(6), (vector<int>{3, 3}));
}

TEST(PrimeSum, Small_8_LexicographicallySmaller) {
    // 8 = 3+5 (valid), 8 != 1+7 (1 not prime), so unique.
    EXPECT_EQ(primeSum(8), (vector<int>{3, 5}));
}

TEST(PrimeSum, Small_10) {
    // 10 = 3+7, 5+5 also works but lexicographically smaller is [3,7]
    EXPECT_EQ(primeSum(10), (vector<int>{3, 7}));
}

TEST(PrimeSum, Small_12_LexicographicallySmaller) {
    // 12 = 5+7 also works, but [5,7] vs [??] => the smallest first prime is 5.
    EXPECT_EQ(primeSum(12), (vector<int>{5, 7}));
}

TEST(PrimeSum, Medium_18_LexicographicallySmaller) {
    // 18 = 5+13, 7+11 also works -> choose [5,13]
    EXPECT_EQ(primeSum(18), (vector<int>{5, 13}));
}

TEST(PrimeSum, Medium_20_LexicographicallySmaller) {
    // 20 = 3+17, 7+13 also works -> choose [3,17]
    EXPECT_EQ(primeSum(20), (vector<int>{3, 17}));
}

TEST(PrimeSum, Medium_26_LexicographicallySmaller) {
    // 26 = 3+23, 7+19, 13+13 -> choose [3,23]
    EXPECT_EQ(primeSum(26), (vector<int>{3, 23}));
}

TEST(PrimeSum, Medium_50_LexicographicallySmaller) {
    // 50 = 3+47 (prime), also 7+43, 13+37, 19+31 -> choose [3,47]
    EXPECT_EQ(primeSum(50), (vector<int>{3, 47}));
}

TEST(PrimeSum, Medium_100_LexicographicallySmaller) {
    // 100 = 3+97 (prime), also 11+89, 17+83, 29+71, 47+53 -> choose [3,97]
    EXPECT_EQ(primeSum(100), (vector<int>{3, 97}));
}

TEST(PrimeSum, Hard_1000_LexicographicallySmaller) {
    //1000=3+997
    EXPECT_EQ(primeSum(1000), (vector<int>{3, 997}));
}

TEST(PrimeSum, Hard_100000_LexicographicallySmaller) {
    // 100000 = 17+99983 works; smaller candidates fail:
    // 3+99997 (99997 not prime), 5+99995, 7+99993, 11+99989 (99989 not prime), 13+99987, ...
    EXPECT_EQ(primeSum(100000), (vector<int>{11, 99989}));
}

