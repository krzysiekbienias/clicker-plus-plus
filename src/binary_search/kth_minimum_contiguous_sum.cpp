#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.

static int countingSubarrays(const std::vector<int>& nums,int lessThan)
{
    int l=0;
    int localSum=0;
    int res=0;
    for (int r = 0; r < nums.size(); ++r)
    {
        localSum+=nums[r];
        while (localSum>lessThan && l<=r)
        {
            localSum-=nums[l];
            l++;

        }
        //now localSum is < lessThan
        res+=(r-l+1);
    }

    return res;
}



int kthSmallestSubarraySum(const std::vector<int> &nums, int k) {
    int low=*min_element(nums.begin(),nums.end());
    int high=std::accumulate(nums.begin(),nums.end(),0);
    int res=0;
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        int count =countingSubarrays(nums,mid);
        if (count>=k)
        {
        res=mid;
        high=mid-1;
        }
        else
        {
            low=mid+1;
        }

    }
    return res;

}
