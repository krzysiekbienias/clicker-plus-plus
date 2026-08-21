#include "numbers_theory/functions_involving_prime_factors.hpp"
#include "numbers_theory/prime_factors.hpp"
#include "competitive_programming/binary_exponential.hpp"
#include <vector>
#include <string>
#include <unordered_map>


using std::vector;
using std::string;
using std::unordered_map;

// Implement your logic here.
int countNbOfDivisors(int num){
    int result=1;
    unordered_map<int,int> factors=primeFactorsMap(num);
    for (auto const &[_,v] :factors){
        result*=(v+1);
    }
    return result;

}

int sumOfDivisors(int num){
    int res=1;
    unordered_map<int,int> factors=primeFactorsMap(num);
    for (auto const &[k,v] :factors){
        long long num=binExponential(k, v+1)-1;
        int denom=k-1;
        res*=num/denom;
    }
    return res;
}