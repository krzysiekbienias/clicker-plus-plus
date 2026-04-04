#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

int maxSatisfied(std::vector<int> &customers, std::vector<int> &grumpy, int minutes) {
    int totalSatisfied=0;
    int n=customers.size();
    int l=0;
    int localExtraGain=0;
    int maxGain=0;
    for (int r=0; r < n; ++r)
    {
        if (grumpy[r]==1)
        {
            localExtraGain+=customers[r];
        }
        else
        {
            totalSatisfied+=customers[r];
        }
        int elementsInWindows=r-l+1;
        if (elementsInWindows>minutes)
        {
            if (grumpy[l]==1)
            {
                localExtraGain-=customers[l];
            }
            l++;
        }
        maxGain=std::max(maxGain,localExtraGain);
    }
    return totalSatisfied+maxGain;
}