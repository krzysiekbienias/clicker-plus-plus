#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.

int countingSubarrays(std::vector<int> nums,int lessThan)
{
    int l=0;
    int localSum=0;
    int res=0;
    for (int r = 0; r < nums.size(); ++r)
    {
        localSum+=nums[r];
        while (localSum>=lessThan && l<=r)
        {
            localSum-=nums[l];
            l++;

        }
        //now localSum is < lessThan
        res+=(r-l+1);
    }

    return res;
}
