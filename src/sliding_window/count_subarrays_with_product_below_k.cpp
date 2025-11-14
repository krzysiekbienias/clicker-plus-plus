#include "std_aliases.hpp"


using namespace stl;

int countSubarraysWithProductBelowK(vector<int>nums,int k) {
    //edge case
    if (k<=1) return 0;
    int ans=0;
    int prod =1;
    size_t l=0;
    for (size_t r=0;r<nums.size();++r) {
        prod*=nums[r];
        while (prod>=k&&l<=r) {
            prod/=nums[l];
            ++l;
        }
        ans+=l<=r?(r-l+1):0;
    }
    return ans;
}