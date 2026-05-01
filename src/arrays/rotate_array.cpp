#include <vector> 


void rotateWithExtraArray(std::vector<int>& nums, int k)
{
    if (nums.empty()) return;
    int n=nums.size();

    k=k%n; // avoid redundant full rotations (e.g. k=7 on n=7 is a no-op)
    if (k==0) return;
    std::vector<int> res(n);

    for (int i=0;i<n;i++)
    {
        int newIdx=(i+k)%n;
        res[newIdx]=nums[i];
    }


    nums = std::move(res); // write back via ref; move avoids an extra O(n) copy
}