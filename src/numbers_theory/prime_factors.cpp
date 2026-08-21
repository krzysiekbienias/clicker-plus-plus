#include <std_aliases.hpp>
using namespace stl;

vector<int> primeFactors(int n) {
    vector<int> results;
    if (n<=1) return {};
    //special check for even numbers to decrease the numbers of iterations
    while (n%2==0) {
        results.push_back(2);
        n/=2;
    }
    for (int p=3;p*p<=n;p+=2) {
        while (n%p==0) {
            results.push_back(p);
            n/=p;
        }
    }
    //to capture the last big prime number
    if (n>1) results.push_back(n);
    return results;
}

unordered_map<int,int> primeFactorsMap(int n){
    unordered_map<int,int> res;
    while (n%2==0){
        res[2]++;
        n/=2;
    }
    for(int i=3;i*i<=n;i+=2){
        while(n%i==0){
            res[i]++;
            n/=i;

        }
    }
    if (n>1){
        res[n]++;
    }
    return res;
}


