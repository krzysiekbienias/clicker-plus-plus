#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
bool zeroSumSubarray(const vector<int>& nums)
{
    if (nums.empty()) return false;
    int prefixSum = 0;
    unordered_set<int> seenPrefixSum;
    for (int x : nums)
    {
        prefixSum += x;
        //we want to return true if the prefix has been already seen.
        bool inserted = seenPrefixSum.insert(prefixSum).second;
        if (prefixSum == 0 || !inserted)
            return true;
    }
    return false;
}
