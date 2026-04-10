#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
float blackjackProbability(int target, int startingHand) {
    vector<float> dp(target+11,0.0);
    int n=dp.size();
    //base case
    for (int S = 0; S < n; ++S) //S is the actual sum of points
    {
        if (S>=target -4 && S<=target)
        {
            continue;
        }
        if (S>target) dp[S]=1.0;
    }
    for (int currentSum = target-5; currentSum >=startingHand ; --currentSum)
    {
        for (int i = 1; i <=10 ; ++i)
        {
            dp[currentSum]+=0.1*dp[currentSum+i];
        }
    }
    return dp[startingHand];
}