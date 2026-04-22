#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
int findMaxConsecutiveOnes(const std::vector<int>& nums) {
    int maxLen = 0;
    int localLen = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 1) {
            localLen++;
            maxLen = std::max(maxLen, localLen);
        } else
            localLen = 0;
    }
    return maxLen;
}
