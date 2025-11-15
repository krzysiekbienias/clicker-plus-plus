#include <std_aliases.hpp>
#include "numbers_theory/all_factors.hpp"
using namespace stl;



int commonFactors(int a, int b) {
    vector<int> aFactors=allFactors(a);
    vector<int> bFactors=allFactors(b);
    int cnt=0;
    for (int x :aFactors){
        if (find(bFactors.begin(),  bFactors.end(), x)!=bFactors.end())
            cnt++;
    }

    return cnt;
}