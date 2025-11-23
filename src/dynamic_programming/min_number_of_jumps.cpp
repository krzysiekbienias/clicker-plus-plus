#include <std_aliases.hpp>
using namespace stl;

int minNumberOfJumps(vector<int> array) {
    int n=array.size();
    vector<int> dp(n,INT_MAX);
    dp[0]=0;
    for (int i=1;i<n;++i) {
        for (int j=0;j<i;++j) {
            if (j+array[j]>=i && dp[j]!=INT_MAX) {
                dp[i]=std::min(dp[i],dp[j]+1);
            }
        }
    }
    return dp[n-1];
}