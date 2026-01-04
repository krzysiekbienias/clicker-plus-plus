#include <std_aliases.hpp>

using namespace stl;
// Implement your logic here.
int connectRopes(const vector<int> &ropes) {
    //edge cases:
    if (ropes.size() <= 1) return 0;
    if (ropes.size() == 2) return ropes[0] + ropes[1];
    priority_queue<int, vector<int>, std::greater<int> > minHeap;
    for (int r: ropes) {
        minHeap.push(r);
    }
    int totalCost = 0;
    while (minHeap.size() > 1) {
        const int top = minHeap.top();
        minHeap.pop();
        const int secondTop = minHeap.top();
        minHeap.pop();
        int tempSum = top + secondTop;
        totalCost += tempSum;
        minHeap.push(tempSum);
    }
    return totalCost;
}
