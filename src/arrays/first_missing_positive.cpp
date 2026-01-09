#include <std_aliases.hpp>
using namespace stl;

//sorting allowed
int firstMissingPositiveSortingAllowed(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int candidate = 1;
    //disregard all negative
    auto it = std::lower_bound(nums.begin(), nums.end(), 1);
    for (; it != nums.end(); ++it)
    {
        int x = *it;
        if (x < candidate)
        {
            continue;
        }
        if (candidate == x)
        {
            candidate++; //
        }
        else return candidate;
    }
    return candidate;
}


int firstMissingPositive(vector<int>& nums)
{
    if (nums.empty()) return 1;
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        int x = nums[i];
        while (x <= n && x >= 1)
        {
            int targetIndex = x - 1;
            //if x is in the right place, or we have duplicate ->break
            if (nums[targetIndex]==x) break;
            std::swap(nums[i],nums[targetIndex]);
            //update x
            x=nums[i];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] != i + 1) return i + 1;
    }
    return n + 1;
}
