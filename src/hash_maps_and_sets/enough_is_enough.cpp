#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

std::vector<int> enoughIsEnough(std::vector<int> arr, int n)
{   vector<int> res;
    unordered_map<int,int> seenCounter;
    for (int x:arr)
    {
        seenCounter[x]++;
        if (seenCounter[x]<=n)
        {
            res.push_back(x);
        }

    }
    return res;
}
