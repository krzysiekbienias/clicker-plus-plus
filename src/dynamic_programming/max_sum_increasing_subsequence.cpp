#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;


vector<vector<int>> maxSumIncreasingSubsequence(const vector<int> &arr)
{   int n =arr.size();
    vector<int> parent(n,-1);
    vector<int> dp=arr; //becasue a single element is its own subsequence
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[j]<arr[i])
            {
                if (dp[j]+arr[i]>dp[i])
                {
                    dp[i]=dp[j]+arr[i];
                    parent[i]=j; //drop the okruszek!!
                }
            }
        }
    }
    auto it=max_element(dp.begin(),dp.end());
    //I need to convert it in index
    int bestIdx=it-dp.begin();
    vector<int> res;
    while (bestIdx!=-1)
    {
        res.push_back(arr[bestIdx]);
        bestIdx=parent[bestIdx];
    }
    std::reverse(res.begin(),res.end());

    return {{*it},res};
}