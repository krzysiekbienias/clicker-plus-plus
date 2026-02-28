#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
int removeElement(vector<int>& nums, int toRemove)
{
    int write = 0;
    int n = nums.size();
    for (int read = 0; read < n; ++read)
    {
        if (nums[read] != toRemove)
        {
            nums[write] = nums[read];
            write++;
        }
    }
    return write;
}
