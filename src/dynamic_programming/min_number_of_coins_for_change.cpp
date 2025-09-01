#include <vector>


int minNumberOfCoinsForChange(int n, std::vector<int> denoms) {
    std::vector<int> dp(n+1,INT_MAX);
    //base case
    //if target (n) is zero, then we need zero coins.
    dp[0]=0;
    for (int i=1;i<n+1;++i) {
        for (int coin :denoms) {
            if (i-coin>=0 && dp[i-coin]!=INT_MAX) {
                dp[i]= std::min(dp[i],1+dp[i-coin]);
            }
        }
    }
    if (dp[n]!=INT_MAX) {
        return dp[n];
    }
    return -1;
}