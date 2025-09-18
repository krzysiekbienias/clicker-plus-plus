#include <vector>

//simpler version that returns subarray
int longestSubarrayWithSumWindowLength(const std::vector<int>& array, int targetSum) {
    int l=0;
    int currentSum=0;
    int n=array.size();
    int candidateWindow=0;
    int maxWindow=0;
    //right pointer always will be moved
    for (int r=0;r<n;++r) {
        currentSum+=array[r];
        while (l<=r && currentSum>targetSum) {
            currentSum-=array[l];
            ++l;
        }
        if (currentSum==targetSum) {
            candidateWindow=r-l+1;
            maxWindow=std::max(candidateWindow,maxWindow);
        }
    }
    return maxWindow;
    }


std::vector<int> longestSubarrayWithSumInterval(const std::vector<int>& array, int targetSum) {
    int l=0;
    int currentSum=0;
    int n=array.size();
    int candidateWindow=0;
    int maxWindow=0;
    int bestL=-1;
    int bestR=-1;
    //right pointer always will be moved
    for (int r=0;r<n;++r) {
        currentSum+=array[r];
        while (l<=r && currentSum>targetSum) {
            currentSum-=array[l];
            ++l;
        }
        if (currentSum==targetSum) {
            candidateWindow=r-l+1;
            maxWindow=std::max(candidateWindow,maxWindow);
            bestL=l;
            bestR=r;
        }
    }
    if (bestL==-1) {
        return {};
    }
    return {bestL,bestR};
}