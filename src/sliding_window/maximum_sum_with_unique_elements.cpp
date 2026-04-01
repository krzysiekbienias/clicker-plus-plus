#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;


int maximumUniqueSubarray(const vector<int>&nums)
{
    int left=0;
    int right=0;
    int currentSum=0;
    int globalMax=INT_MIN;
    unordered_map<int,int> countingMap;
    while (right<nums.size())
    {
        countingMap[nums[right]]++;
        currentSum+=nums[right];
        while (countingMap[nums[right]]>1)
        {
            countingMap[nums[left]]--;
            currentSum-=nums[left];
            left++;
        }
        globalMax=std::max(globalMax,currentSum);
        right++;


    }
    return globalMax;
}
