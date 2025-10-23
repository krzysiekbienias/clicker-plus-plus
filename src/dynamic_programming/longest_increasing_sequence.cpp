
#include "std_aliases.hpp"
using namespace stl;

// Implement your longest_increasing_sequence logic here.


vector<int> longestIncreasingSubsequence(const vector<int> &arr ) {
    size_t n =arr.size();
    vector<int> dp(n,1);
    vector<int> prev(n,-1); //remember how we get from j to j
    if (arr.empty()) return {};
    for (int i=1;i<n;i++) {
        for (int j=0;j<i;++j) {
            if (arr[j]<arr[i] && dp[j]+1>dp[i]) {
                dp[i]=dp[j]+1;
                prev[i]=j;
            }
        }
    }
    auto it=std::max_element(dp.begin(),dp.end());

    size_t bestEndIdx=static_cast<size_t>(std::distance(dp.begin(),it));
    vector<int> res;
    for (int k=(int) bestEndIdx;k!=-1;k=prev[k])
        res.push_back(arr[k]);
    std::reverse(res.begin(),res.end());

    return res;
}