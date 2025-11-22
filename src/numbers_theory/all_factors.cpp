# pragma once
#include <std_aliases.hpp>
using namespace stl;

vector<int> allFactors(int n) {
    vector<int> results;

    for (int p=1;p*p<=n;p++) {
        if (n%p==0) {
            results.push_back(p);
            if (p!=n/p) results.push_back(n/p);

        }
    }
    //to capture the last big prime number
    std::sort(results.begin(),results.end());
    return results;

}
