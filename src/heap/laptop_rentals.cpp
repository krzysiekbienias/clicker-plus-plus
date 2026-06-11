#include <functional>
#include <queue>
#include <std_aliases.hpp>
#include <vector>

using namespace stl;

int laptopRentals(vector<vector<int>> times) {
    int res=0;
    int n = times.size();
    std::priority_queue<int, vector<int>,std::greater<int>> minHeap;

    sort(times.begin(),times.end());

    for(int i=0;i<n;i++){
        int nextStart=times[i][0];
        int nextEnd=times[i][1];

        while (!minHeap.empty() && minHeap.top()<=nextStart)
        {
            minHeap.pop();
        }
        minHeap.push(nextEnd);
        res=std::max(res,(int)minHeap.size());

    }
    
    return res;
}
