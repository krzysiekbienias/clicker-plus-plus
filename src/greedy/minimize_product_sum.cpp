#include <std_aliases.hpp>
#include <queue>


//to jest wersja gdzie moge obie wersje posortowac ale nie tak mowi zadanie. 
static int minProductSumWithSortingBoth(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::sort(nums1.begin(),nums1.end());
    std::sort(nums2.rbegin(),nums2.rend());
    int sum=0;
    for (int i = 0; i < nums1.size(); ++i)
    {
        sum+=nums1[i]*nums2[i];
    }
    return sum;
}


//finds the minimum possible product sum **after rearranging the order of the elements in `nums1`
// czyli jakby tylko mozna jedna zrobic :) 

int minProductSum(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::sort(nums1.begin(),nums1.end());
    std::priority_queue<int> maxHeap;
    for (int x : nums2) {
        maxHeap.push(x);
    }
    int sum = 0;
    for (int i = 0; i < static_cast<int>(nums1.size()); ++i) {
        sum += nums1[i] * maxHeap.top();
        maxHeap.pop();
    }
    return sum;
}