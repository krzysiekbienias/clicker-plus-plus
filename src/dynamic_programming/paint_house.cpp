#include <algorithm>
#include <vector>



int minCost(std::vector<std::vector<int>>& costs) {
        int rows = costs.size();
        std::vector<std::vector<int>> dp(rows, std::vector<int>(3, 0));
        dp[0]=costs[0];

        for (int i = 1; i < rows; i++) {
            dp[i][0]=costs[i][0]+std::min(dp[i-1][1],dp[i-1][2]);
            dp[i][1]=costs[i][1]+std::min(dp[i-1][0],dp[i-1][2]);
            dp[i][2]=costs[i][2]+std::min(dp[i-1][0],dp[i-1][1]);

        }
        return std::min({dp[rows-1][0],dp[rows-1][1],dp[rows-1][2]});
    
}
