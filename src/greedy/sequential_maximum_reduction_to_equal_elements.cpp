#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
int sequentialMaximumReductionToEqualElements(std::vector<int> &nums) {
    std::sort(nums.begin(),nums.end());
    int operations=0;
    int levels=0;
    int n=nums.size();
    for (int i=1;i<n;i++){
        if(nums[i-1]!=nums[i])
        {
            levels++;
        }
        operations+=levels;
    }
    return operations;
}