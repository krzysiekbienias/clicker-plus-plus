#include "numbers_theory/sieve_of_eratosthenes.hpp"
#include <gtest/gtest.h>
#include <std_aliases.hpp>

using namespace stl;

TEST(SieveOfEratosthenes, SieveSmallValues) {
    EXPECT_EQ(sieve(0), (vector<char>{0}));
    EXPECT_EQ(sieve(1), (vector<char>{0, 0}));
    EXPECT_EQ(sieve(5), (vector<char>{0, 0, 1, 1, 0, 1}));
}

TEST(SieveOfEratosthenes, SieveUpToTen) {
    vector<char> expected = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0};
    EXPECT_EQ(sieve(10), expected);
}

TEST(SieveOfEratosthenes, PrimeNumbersSmall) {
    EXPECT_EQ(primeNumbers(1), (vector<int>{}));
    EXPECT_EQ(primeNumbers(2), (vector<int>{2}));
    EXPECT_EQ(primeNumbers(10), (vector<int>{2, 3, 5, 7}));
    EXPECT_EQ(primeNumbers(20), (vector<int>{2, 3, 5, 7, 11, 13, 17, 19}));
}

TEST(SieveOfEratosthenes, SieveMatchesPrimeNumbers) {
    const int n = 50;
    const vector<char> isPrime = sieve(n);
    vector<int> primesFromSieve;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primesFromSieve.push_back(i);
        }
    }
    EXPECT_EQ(primesFromSieve, primeNumbers(n));
}

TEST(SieveOfEratosthenes, NthPrime) {
    EXPECT_EQ(nthPrime(1), 2);
    EXPECT_EQ(nthPrime(2), 3);
    EXPECT_EQ(nthPrime(3), 5);
    EXPECT_EQ(nthPrime(6), 13);
    EXPECT_EQ(nthPrime(25), 97);
}

TEST(SieveOfEratosthenes, NthPrimeInvalidInput) {
    EXPECT_THROW(nthPrime(0), std::invalid_argument);
    EXPECT_THROW(nthPrime(-1), std::invalid_argument);
}
