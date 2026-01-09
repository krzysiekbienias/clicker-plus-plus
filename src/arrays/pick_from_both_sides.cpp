#include <std_aliases.hpp>
using namespace stl;

int maxSumFromEnds(const vector<int>&arr,int b) {
    vector<int> leftSum(b+1, 0);
    vector<int> rightSum(b+1, 0);
    int maxSum=INT_MIN;
    int n=arr.size();
    for (int i = 1; i <=b; i++)
    {
        leftSum[i] = leftSum[i - 1] + arr[i-1];
    }

    for (int i = 1; i <=b ; i++)
    {
        rightSum[i]=rightSum[i -1] + arr[n-i];
    }
    for (int i=0;i<=b;++i) {
        maxSum=std::max(maxSum,leftSum[i]+rightSum[b-i]);
    }
    return maxSum;
}