#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

int levenshteinDistance(string str1, string str2)
{
    if (str1.empty() && str2.empty()) return 0;
    string base=str1;
    string target=str2;
    int n=base.size();
    int m=target.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for (int i = 1; i < n+1; ++i)
    {
        dp[i][0]=i;
    }
    for (int j = 1; j < m+1; ++j)
    {
        dp[0][j]=j;
    }

    for (int i=0;i<n+1;++i)
    {
        for (int j = 0; j < m+1; ++j)
        {
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    for (int i = 1; i < n+1; ++i)
    {
        for (int j = 1; j < m+1; ++j)
        {
            if (base[i-1]==target[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=1+std::min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
            }
        }
    }
    return dp[n][m];
}
