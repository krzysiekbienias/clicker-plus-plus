#include "dynamic_programming/subset_that_sum_to_k.hpp"

#include "std_aliases.hpp"

using namespace std;

// Implement your subset_that_sum_to_k logic here.
int subsetSum(const vector<int> &arr, int k) {
    int fullArrSum = std::accumulate(arr.begin(), arr.end(), 0);
    if (k > fullArrSum) return 0;
    if (arr.empty()) return 0;
    //container
    int rows = arr.size();
    VVI dp(rows, VI(k + 1, 0));

    int singletonVal = arr[0];
    dp[0][0] = 1;
    if (arr[0] <= k) {
        dp[0][arr[0]] = 1;
    }
    for (int i = 1; i < rows; ++i) {
        for (int j = 0; j < k + 1; ++j) {
            if (j - arr[i] < 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i]];
            }
        }
    }
    return dp[rows - 1][k];
}

bool subsetSumExistence(const vector<int> &arr, int k) {
    int fullArrSum = std::accumulate(arr.begin(), arr.end(), 0);
    if (k > fullArrSum) return false;
    if (arr.empty()) return false;
    //container
    int rows = arr.size();
    vector<vector<bool> > dp(rows, vector<bool>(k + 1, 0));

    int singletonVal = arr[0];
    dp[0][0] = true;
    if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }
    for (int i = 1; i < rows; ++i) {
        for (int j = 0; j < k + 1; ++j) {
            if (j - arr[i] < 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i]];
            }
        }
    }
    return dp[rows - 1][k];
}


int subsetSumUnbounded(vector<int> &arr,int n)
{
    vector<int> dp(n+1,0);
    dp[0]=1;
    //sorting allows early termination and is not dominant
    sort(arr.begin(),arr.end());
    for (int x:arr)
    {
        for (int i = x; i < n+1; ++i)
        {
            {
                dp[i]+=dp[i-x];
            }
        }
    }
    return dp[n];
}


int subsetSumArrLengthConstrain(vector<int> &arr,int n)
{
    vector<vector<int>> dp(arr.size()+1,vector<int>(n+1,0));
    dp[0][0]=1;
    return -1;
}
