#include "std_aliases.hpp"

using namespace stl;

int firstRepeatingCharacter(vector<int>& A) {
    unordered_map<int,int> um;
    for (int x:A) {
        um[x]++;
    }
    for (int k:A) {
        if (um[k]>1) return k;
    }
    return -1;
}