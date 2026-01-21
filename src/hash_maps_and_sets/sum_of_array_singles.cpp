#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

int sumOfArraySingles(std::vector<int> v)
{
    int res = 0;
    unordered_map<int, int> um;
    for (int x : v)
    {
        um[x]++;
    }
    for (auto& x : um)
    {
        if (x.second == 1)
        {
            res += x.first;
        }
    }
    return res;
}

int sumOfArraySinglesSetVersion(std::vector<int> v)
{
    int res=0;
    unordered_set<int> seen;
    for (int x:v)
    {
        if (seen.insert(x).second)
        {
            res+=x;
        }
        else
        {
            res-=x;
        }
    }
    return res;

}
