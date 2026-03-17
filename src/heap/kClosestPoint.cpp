#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;


std::vector<std::vector<int>> kClosestPoint(std::vector<std::vector<int>> &points, int k) {
    std::vector<std::vector<int>> res;
    using heapEntry= pair<double,pair<int,int>> ;

    //priority_queue<heapEntry,std::vector<heapEntry>,std::greater<heapEntry>> minHeap;
    priority_queue<heapEntry> maxHeap;
    double d=0;
    for (int i = 0; i < k; ++i)
    {   int x=points[i][0];
        int y=points[i][1];
        d=sqrt(x*x+y*y);
        maxHeap.push({d,{x,y}});
    }
    for (int j = k; j < points.size(); ++j)
    {   int x = points[j][0];
        int y = points[j][1];
        d = sqrt(x * x + y * y);
        auto top=maxHeap.top();
        if (d<top.first)
        {
            maxHeap.pop();
            maxHeap.push({d,{points[j][0],points[j][1]}});
        }
    }
    res.reserve(k);
    while (!maxHeap.empty())
    {   auto topElement=maxHeap.top().second;
        res.push_back({topElement.first,topElement.second});
        maxHeap.pop();
    }
    return res;
}