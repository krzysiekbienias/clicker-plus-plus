#include<vector>
#include "dynamic_programming/lis.hpp"
#include "std_aliases.hpp"

using namespace stl;

// Implement your lis_len logic here.
int longestIncreasingSubsequenceLen(const std::vector<int>& arr)
{
    int n = arr.size();
    // edge case

    if (n == 0) return 0;
    // dp[i] stores the length of the LIS ending at index i
    std::vector<int> dp(arr.size(), 1);
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }
    return *std::max_element(dp.begin(), dp.end());
}


int lisWithBinarySearchLen(const std::vector<int>& arr)
{
    std::vector<int> tails;
    tails.reserve(arr.size());
    for (int x : arr)
    {
        auto it = std::lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end())
            tails.push_back(x);
        else
        {
            *it = x;
        }
    }
    return (int)tails.size();
}

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