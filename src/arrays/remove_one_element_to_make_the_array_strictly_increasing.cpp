#include "std_aliases.hpp"

using namespace stl;

bool canBeIncreasing(vector<int>& nums) {
    if (nums.size()<=2) return true;

    int prev=nums[0];
    bool removed =false;

    for (int i=1;i<nums.size();++i) {
        if (nums[i]>prev) {
            //a strict increase sequence
            prev=nums[i];
        }
        else {
            if (removed) return false;
            removed=true;
            if (i<2 || nums[i]>nums[i-2]) {
                prev=nums[i];
            }
        }
    }
    return true;
}