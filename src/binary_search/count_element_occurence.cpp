#include <std_aliases.hpp>

using namespace stl;

int findCount(const vector<int> &nums,int target) {
    int n=(int)nums.size();
    auto lbIdx=std::lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    auto ubIdx=std::upper_bound(nums.begin(),nums.end(),target)-nums.begin();
    int cnt=ubIdx-lbIdx;
    if (lbIdx==n || nums[lbIdx]!=target) return 0;
    return cnt;
}



