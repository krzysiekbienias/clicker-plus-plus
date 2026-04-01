#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

std::vector<int> nextPermutation(std::vector<int> &nums) {
    int n=nums.size();
    int i=n-2;
    int j=n-1;
    for ( ; i >=0 ; --i) //from right
    {
        if (nums[i+1]>nums[i])
        {
            break;
        }
    }
    if (i<0)
    {   reverse(nums.begin(),nums.end());
        return nums;
    }
    for (; j >=0 ; --j) //from right
    {
        if (nums[j]>nums[i])
        {
            std::swap(nums[j],nums[i]);
            break;
        }
    }
    reverse(nums.begin()+i+1,nums.end());
    return nums;
}
