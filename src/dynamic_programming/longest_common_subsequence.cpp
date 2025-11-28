#include <std_aliases.hpp>
using namespace stl;

//interviewBit
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
//AlgoExpert
vector<char> longestCommonSubsequenceExplicit(string A,string B) {

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
    //we go backward
    int i=rows-1;
    int j=cols-1;
    vector<char> res;
    while (i>0 && j>0) {
        if (A[i-1]==B[j-1]) {
            res.push_back(A[i-1]);
            --i;
            --j;
        }
        else {
            //<--- we check how we get here from left or top
            if (dp[i-1][j]>=dp[i][j-1]) {
                --i;
            }
            else --j;

        }
    }
    return res;
}

