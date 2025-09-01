# include <vector>

// Implement your minimum_coin_combination logic here.
int numberOfWaysToMakeChange(int n, std::vector<int> denoms) {
    std::vector<int> dp(n+1,0);
    dp[0]=1;
    for (auto coin : denoms) {
        for (int i =1;i<n+1;++i) {
            if (i-coin>=0) {
                dp[i]+=dp[i-coin];
            }
        }
    }

    return dp[n];
}
