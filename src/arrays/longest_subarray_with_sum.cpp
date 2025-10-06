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
    //right pointer will always be moved typically for sliding window pattern.
    for (int r=0;r<n;++r) {
        currentSum += array[r];
        while (l <= r && currentSum > targetSum) {
            currentSum -= array[l];
            ++l;
        }
        if (currentSum == targetSum) {
            candidateWindow = r - l + 1;
            // This condition ensures we don’t overwrite a longer valid interval with a shorter one.
            // Example: target = 7 can be formed as 1+1+1+1+1+1+1 or 3+4 — we prefer the longer interval.
            if (candidateWindow > maxWindow) {
                maxWindow = candidateWindow;
                bestL = l;
                bestR = r;
            }
        }
    }
    if (bestL==-1) {
        return {};
    }

    return {bestL,bestR};
}