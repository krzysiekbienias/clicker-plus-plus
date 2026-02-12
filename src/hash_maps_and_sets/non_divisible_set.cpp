#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
int nonDivisibleSubset(int k, vector<int> s)

{
    //reminder is 0,1,2...k-1, so it is ideal to use as a container
    int res = 0;
    vector<int> v(k, 0);
    for (int x : s)
    {
        int r = x % k;
        v[r]++;
    }
    res += std::min(1, v[0]);
    int stopCond = floor((k - 1) / 2);
    for (int r = 1; r <= stopCond; ++r)
    {
        res += std::max(v[r], v[k - r]);
    }
    if (k % 2 == 0)
    {
        res += std::min(1, v[k / 2]);
    }
    return res;
}
