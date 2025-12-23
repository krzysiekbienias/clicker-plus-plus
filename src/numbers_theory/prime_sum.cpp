#include <std_aliases.hpp>

using namespace stl;

vector<char> sieve(int n) {
    vector<char> isPrime(n + 1, 1);
    //out of bounds protection
    if (n >= 0) isPrime[0] = 0;
    if (n >= 1) isPrime[1] = 0;

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int multiple = p * p; multiple <= n; multiple += p) {
                isPrime[multiple] = 0;
            }
        }
    }
    return isPrime;
}

vector<int> primeSum(int n) {
    vector<int> res;
    vector<char> sieveVec = sieve(n);
    for (int i = 2; i <= n / 2; ++i) {
        if (sieveVec[i] && sieveVec[n - i]) {
            return {i, n - i};
        }
    }
    return {}; //should never happen, according to conjecture.
}
