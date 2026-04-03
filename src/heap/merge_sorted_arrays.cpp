#include <std_aliases.hpp>
#include <queue>
#include <tuple>
using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
vector<int> mergeSortedArrays(vector<vector<int>> arrays) {
    vector<int> res;
    priority_queue<std::tuple<int,int,int>,vector<std::tuple<int,int,int>>, std::greater<std::tuple<int,int,int>>> minHeap;
    //inititiazation
    int n=arrays.size();
    for (int i = 0; i < n; ++i)
    {   if (!arrays[i].empty())
        minHeap.push({arrays[i][0],i,0});
    }
    while (!minHeap.empty())
    {
        auto temp=minHeap.top();
        minHeap.pop();
        res.push_back(std::get<0>(temp));
        int arrIdx=std::get<1>(temp);
        int elemIdx=std::get<2>(temp);
        if (elemIdx+1<arrays[arrIdx].size())
        {   int newValue=arrays[arrIdx][elemIdx+1];
            minHeap.push({newValue,arrIdx,elemIdx+1});
        }
    }
    return res;
}