#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
vector<int> findOccurences(const vector<int> &nums){
    if (nums.empty()) return {};
    vector<int> res;
    unordered_map<int,int> um;
    for (int x:nums)
    {
        um[x]++;
    }
    vector<int> keys;
    for (auto& item:um)
    {
    keys.push_back(item.first);
    }
    std::sort(keys.begin(),keys.end());
    for (int x:keys)
    {
        res.push_back(um[x]);
    }
    return res;
}