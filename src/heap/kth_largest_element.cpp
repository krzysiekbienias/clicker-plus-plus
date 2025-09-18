#include "heap/kth_largest_element.hpp"
#include <queue>

// Implement your kth_largest_element logic here.

int kthGratestValue(std::vector<int> nums,int k){
    std::priority_queue<int,std::vector<int>,std::greater<int>> minHeap;
    //we push first k element into the heap.
    for (int i=0;i<k;++i){
        minHeap.push(nums[i]);
    }
    for (int j=k;j<nums.size();++j){
        if(nums[j]>minHeap.top()){
            minHeap.pop();
            minHeap.push(nums[j]);
        }
    }
    return minHeap.top();
}

std::vector<int> kGratestValues(std::vector<int> nums,int k) {
    if (nums.empty() || k<=0) return {};
    std::priority_queue<int,std::vector<int>,std::greater<int>> minHeap;
    //we push first k element into the heap.
    for (int i=0;i<k;++i){
        minHeap.push(nums[i]);
    }
    for (int j=k;j<nums.size();++j){
        if(nums[j]>minHeap.top()){
            minHeap.pop();
            minHeap.push(nums[j]);
        }
    }
    std::vector<int> largestElements;
    largestElements.reserve(k);
    while (!minHeap.empty()) {
        largestElements.push_back(minHeap.top());
        minHeap.pop();
    }
    std::sort(largestElements.rbegin(),largestElements.rend());
    return largestElements;
}
