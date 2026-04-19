#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

std::vector<int> sortByBits(std::vector<int>& arr)
{
    std::sort(arr.begin(),arr.end(),[](int a, int b)
    {
        int cntA=__builtin_popcount(a);
        int cntB=__builtin_popcount(b);
        return (cntA<cntB || (cntA==cntB && a<b));

    });

    return arr;
}
