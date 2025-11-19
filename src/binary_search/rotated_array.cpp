#include <std_aliases.hpp>

using namespace stl;

int findMinInRotatedArray(const vector<int>&nums){
    int leftIdx=0;
    int rightIdx=nums.size()-1;
    while (leftIdx<rightIdx) {
        int mid=leftIdx+(rightIdx-leftIdx)/2;
        if (nums[mid]>nums[rightIdx]) {
            leftIdx=mid+1;
        }
        else rightIdx=mid;
    }
    return nums[leftIdx];
}
