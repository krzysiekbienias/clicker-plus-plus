#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
int findLengthOfLCIS(const std::vector<int>& nums) {
    int maxLen = 1;
    int l = 0;
    int n = nums.size();
    for (int r = 1; r < n; r++) {
        if (nums[r] - nums[r - 1] > 0) {
            int localLen = r - l + 1;
            maxLen = std::max(localLen, maxLen);
        }

        else {
            l = r;
        }
    }
    return maxLen;
}