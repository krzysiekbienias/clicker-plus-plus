#include "numbers_theory/functions_involving_prime_factors.hpp"
#include <gtest/gtest.h>

// countNbOfDivisors(n): liczba dzielnikow n.
// n = p1^a1 * p2^a2 * ...  =>  (a1+1)*(a2+1)*...

TEST(CountNbOfDivisors, One) {
    EXPECT_EQ(countNbOfDivisors(1), 1);
}

TEST(CountNbOfDivisors, Prime) {
    EXPECT_EQ(countNbOfDivisors(2), 2);
    EXPECT_EQ(countNbOfDivisors(7), 2);
    EXPECT_EQ(countNbOfDivisors(13), 2);
}

TEST(CountNbOfDivisors, PrimeSquare) {
    // 4 = 2^2 -> 1,2,4
    EXPECT_EQ(countNbOfDivisors(4), 3);
    // 9 = 3^2 -> 1,3,9
    EXPECT_EQ(countNbOfDivisors(9), 3);
}

TEST(CountNbOfDivisors, PrimeCube) {
    // 8 = 2^3 -> 1,2,4,8
    EXPECT_EQ(countNbOfDivisors(8), 4);
}

TEST(CountNbOfDivisors, TwoDistinctPrimes) {
    // 6 = 2*3 -> 1,2,3,6
    EXPECT_EQ(countNbOfDivisors(6), 4);
    // 15 = 3*5 -> 1,3,5,15
    EXPECT_EQ(countNbOfDivisors(15), 4);
}

TEST(CountNbOfDivisors, Twelve) {
    // 12 = 2^2*3 -> 1,2,3,4,6,12
    EXPECT_EQ(countNbOfDivisors(12), 6);
}

TEST(CountNbOfDivisors, ThirtySix) {
    // 36 = 2^2*3^2 -> 9 dzielnikow
    EXPECT_EQ(countNbOfDivisors(36), 9);
}

TEST(CountNbOfDivisors, Sixty) {
    // 60 = 2^2*3*5 -> 12 dzielnikow
    EXPECT_EQ(countNbOfDivisors(60), 12);
}

TEST(CountNbOfDivisors, Hundred) {
    // 100 = 2^2*5^2 -> 9 dzielnikow
    EXPECT_EQ(countNbOfDivisors(100), 9);
}

TEST(CountNbOfDivisors, PrimePower) {
    // 32 = 2^5 -> 6 dzielnikow
    EXPECT_EQ(countNbOfDivisors(32), 6);
}

// sumOfDivisors(n): suma WSZYSTKICH dzielnikow n (wlacznie z 1 i n).
// n = p1^a1 * p2^a2 * ...  =>  product (p^{a+1}-1)/(p-1)

TEST(SumOfDivisors, One) {
    EXPECT_EQ(sumOfDivisors(1), 1);
}

TEST(SumOfDivisors, Prime) {
    EXPECT_EQ(sumOfDivisors(2), 3);
    EXPECT_EQ(sumOfDivisors(7), 8);
    EXPECT_EQ(sumOfDivisors(13), 14);
}

TEST(SumOfDivisors, PrimeSquare) {
    // 4: 1+2+4=7
    EXPECT_EQ(sumOfDivisors(4), 7);
    // 9: 1+3+9=13
    EXPECT_EQ(sumOfDivisors(9), 13);
}

TEST(SumOfDivisors, PrimeCube) {
    // 8: 1+2+4+8=15
    EXPECT_EQ(sumOfDivisors(8), 15);
}

TEST(SumOfDivisors, TwoDistinctPrimes) {
    // 6: 1+2+3+6=12
    EXPECT_EQ(sumOfDivisors(6), 12);
    // 15: 1+3+5+15=24
    EXPECT_EQ(sumOfDivisors(15), 24);
}

TEST(SumOfDivisors, Twelve) {
    // 12: 1+2+3+4+6+12=28
    EXPECT_EQ(sumOfDivisors(12), 28);
}

TEST(SumOfDivisors, ThirtySix) {
    // 36: 1+2+3+4+6+9+12+18+36=91
    EXPECT_EQ(sumOfDivisors(36), 91);
}

TEST(SumOfDivisors, Sixty) {
    // 60: 1+2+3+4+5+6+10+12+15+20+30+60=168
    EXPECT_EQ(sumOfDivisors(60), 168);
}

TEST(SumOfDivisors, Hundred) {
    // 100: 1+2+4+5+10+20+25+50+100=217
    EXPECT_EQ(sumOfDivisors(100), 217);
}

TEST(SumOfDivisors, PrimePower) {
    // 32: 1+2+4+8+16+32=63
    EXPECT_EQ(sumOfDivisors(32), 63);
}

