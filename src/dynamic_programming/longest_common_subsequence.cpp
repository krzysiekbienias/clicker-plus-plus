#include <std_aliases.hpp>
using namespace stl;

int longestCommonSubsequence(string A,string B) {
    int rows=A.size()+1;
    int cols=B.size()+1;

    VVI dp(rows,VI(cols,0));

    for (int i =1;i<rows;++i) {
        for (int j=1;j<cols;++j) {
            if (A[i-1]==B[j-1]) {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else {
                dp[i][j]=std::max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[rows-1][cols-1];
}

