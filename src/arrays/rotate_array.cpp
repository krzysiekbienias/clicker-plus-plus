#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;


void rotateWithExtraArray(vector<int>& nums, int k)
{
    if (nums.empty()) return;
    int n=nums.size();

    k=k%n;//normalise
    vector<int> res(n);

    for (int i=0;i<n;i++)
    {
        int newIdx=(i+k)%n;
        res[newIdx]=nums[i];
    }

    nums=res;//copy into nums becasue we cannot return it

}