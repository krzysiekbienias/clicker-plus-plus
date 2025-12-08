#include "std_aliases.hpp"

using namespace stl;

vector<int> findDisappearedNumbers(vector<int> &nums) {
    int n = nums.size();
    vector<int> res;
    vector<bool> seen(n, false);
    for (int x: nums) {
        seen[x - 1] = true;
    }
    for (int i = 0; i < n; ++i) {
        if (!seen[i])
            res.push_back(i + 1);
    }
    return res;
}
