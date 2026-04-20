#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
int maxProfitWithColorFullBalls(const std::vector<int> &inventory, int orders) {
    int MOD=1000000007;
    long long profit=0;
    priority_queue<int> maxHeap(inventory.begin(),inventory.end());
    while (!maxHeap.empty() && orders>0)
    {
        int current=maxHeap.top();
        profit=(profit+current)%MOD;
        maxHeap.pop();

        current--;
        orders--;

        if (current>0)
        {
            maxHeap.push(current);
        }


    }
    return profit;
}