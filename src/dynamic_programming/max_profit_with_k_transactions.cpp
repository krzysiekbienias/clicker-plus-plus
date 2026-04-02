#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

int maxProfitWithKTransactions(const vector<int> & prices, int k) {
    int n=prices.size();
    if (n<=1 || k==0)
    {
        return 0;
    }
    vector<vector<int>> dp(k+1,vector<int>(n,0));
    //dp[i][j] -> i is nb of transactions [0,k]

    for (int i = 1; i <=k; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            int maxSoFar=dp[i][j-1]; //do nothing
            for (int m = 0; m < j; ++m)
            {
                int profitFromCurrentTransaction=prices[j]-prices[m]+dp[i-1][m];
                maxSoFar=std::max(maxSoFar,profitFromCurrentTransaction);
            }
            dp[i][j]=maxSoFar;
        }

    }
    return dp[k][n-1];
}
