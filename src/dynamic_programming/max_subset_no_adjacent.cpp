#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
int maxSubsetSumNoAdjacent(vector<int> array)
{
    if (array.empty()) return 0;
    std::size_t n = array.size();
    if (n==1) return array[0];
    if (n==2) return std::max(array[0],array[1]);

    vector<int> dp(n,0);
    dp[0]=array[0];
    dp[1]=std::max(array[0],array[1]);
    for (int i = 2; i < n; ++i)
    {
        dp[i]=std::max(dp[i-1],dp[i-2]+array[i]);
    }
    return dp.back();

}
