#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n=nums.size();
    int i=n-1;
    int j=n-3;
    while(j>=0){
        if(nums[j]+nums[j+1]>nums[i]){
            return nums[j]+nums[j+1]+nums[i];
        }
        i--;
        j=i-2;

    }
    return 0;
}