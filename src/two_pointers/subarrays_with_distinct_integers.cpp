#include <std_aliases.hpp>
#include<two_pointers/subarrays_with_distinct_integers.hpp>
using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
int atMostKDistinct(std::vector<int> nums, int k)
{
    int l = 0;
    int distinct = 0;
    unordered_map<int, int> freq;
    int n = nums.size();
    int res = 0;
    for (int r = 0; r < n; ++r)
    {
        if (++freq[nums[r]] == 1) distinct++;
        while (distinct > k)
        {
            if (--freq[nums[l]] == 0) distinct--;
            l++;
        }
        res += r - l + 1;
    }
    return res;
}

// exact
int exactKDistinct(std::vector<int> nums, int k)
{
    return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
}
