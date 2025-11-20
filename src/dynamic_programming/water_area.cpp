#include <std_aliases.hpp>
using namespace stl;
using namespace io;

int waterArea(vector<int> heights) {
    //edge case
    size_t n=heights.size();
    if (n<2) return 0;

    vector<int> maxFromLeft(n,0),maxFromRight(n,0);
    maxFromLeft[0]=heights[0];
    maxFromRight[n-1]=heights[n-1];
    for (int i=1;i<n;i++) {
        maxFromLeft[i]=std::max(maxFromLeft[i-1],heights[i]);
    }
    for (int i=n-2;i>=0;--i) {
        maxFromRight[i]=std::max(maxFromRight[i+1],heights[i]);
    }

    int maxWater=0;
    for (int j=0;j<n;++j) {
        maxWater+=std::max(0,std::min(maxFromLeft[j],maxFromRight[j])-heights[j]);
    }

    return maxWater;
}
