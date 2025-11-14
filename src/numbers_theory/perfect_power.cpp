#include "std_aliases.hpp"
#include "numbers_theory/prime_factors.hpp"



int isPower(int num) {
    vector<int> primesFact=primeFactors(num);

    map<int,int> exponentsMap;
    for (int pn:primesFact) {
        exponentsMap[pn]++;
    }
    vector <int>allGCD;
    for (auto &items:exponentsMap) {
        allGCD.push_back(items.second);
    }
    int gcd=allGCD[0];
    for (int i=0; i<allGCD.size();++i){
        gcd=std::gcd(gcd,allGCD[i]);
    }
    return gcd>1;
}