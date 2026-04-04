#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

int gapMinimization(std::vector<int> &nums, int k) {
    if (nums.size()==1) return 0;
    std::sort(nums.begin(),nums.end());
    int n=nums.size();
    int res=nums[n-1]-nums[0];
    for (int i = 0; i < n-1; ++i)
    {
        int highCamp=std::max(nums[i]+k,nums[n-1]-k);
        int lowCamp=std::min(nums[0]+k,nums[i+1]-k);
        res=std::min(res,highCamp-lowCamp);
    }
    return res;
}
