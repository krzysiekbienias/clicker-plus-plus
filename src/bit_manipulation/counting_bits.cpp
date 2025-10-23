#include <std_aliases.hpp>

using namespace stl;

vector<int> countBits(int n) {
    vector<int> res;
    for (int i =0;i<=n;i++) {
        int nbOfBits= __builtin_popcount(i);
        res.push_back(nbOfBits);

    }
    return res;
}

//without __builtin_popcount(i)
vector<int> countBitsLowLevel(int n) {
    vector<int> bits1s(n+1,0);
    for (int i =1;i<=n;i++) {
        //start from 1 because 0 does not have any 1s
        bits1s[i]=bits1s[i>>1]+(i&1);
    }
    return bits1s;

}