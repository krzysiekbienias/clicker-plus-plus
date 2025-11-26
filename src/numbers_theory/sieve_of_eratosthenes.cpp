#include <std_aliases.hpp>
using namespace stl;


vector<char> sieve(int n) {
    vector<char> isPrime(n+1,1);
    //out of bounds protection
    if (n>=0) isPrime[0]=0;
    if (n>=1) isPrime[1]=0;

    for (int p=2;p*p<=n;++p) {
        if (isPrime[p]) {
            for (int multiple =p*p;multiple<=n;multiple+=p) {
                isPrime[multiple]=0;
            }
        }
    }
    return isPrime;
}

vector<int> primeNumbers(int n) {
    vector<int> primes={};
    vector<char> isPrime=sieve(n);
    for (int i=2;i<=n;++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int nthPrime(int k) {
    if (k<=0) {
        throw std::invalid_argument("n must be >=1 becasue it is nth number");
    }

    int limit=std::max(15,15*k);
    while (true) {
        std::vector<char> isPrime=sieve(limit);
        int count =0; //we will increase counter until we get k
        for (int i=2;i<=limit;++i) {
            if (isPrime[i]) {
                count++;
                if (count==k) {
                    return i;
                }
            }
        }
        limit*=2;
    }
}
