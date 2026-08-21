#include <std_aliases.hpp>
#include "numbers_theory/sieve_of_eratosthenes.hpp"

using namespace stl;

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
