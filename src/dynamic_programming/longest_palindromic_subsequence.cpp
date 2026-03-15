#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
int longestPalindromeSubseq(string s)
{   int n=s.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    //base case
    for (int i = 0; i < n; ++i)
    {
        {
            dp[i][i]=1;
        }
    }
    for (int gap = 1; gap < n; ++gap)
    {
        for (int i = 0; i + gap< n; ++i)
        {
            int j=i+gap;
            if (s[i]==s[j])
            {
                dp[i][j]=dp[i+1][j-1]+2;
            }
            else
            {
                dp[i][j]=std::max(dp[i][j-1],dp[i+1][j]);
            }

        }
    }
    return dp[0][n-1];
}