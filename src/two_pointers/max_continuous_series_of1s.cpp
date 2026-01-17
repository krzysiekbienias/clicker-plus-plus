#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.

vector<int> maxContinuousSeriesOf1s(vector<int> nums,int k)
{
    int l=0;
    int nbOfZeros=0;
    int n=nums.size();
    int bestL=0;
    int bestR=-1;
    int bestWindowLen=0;
    for (int r = 0; r <  n; ++r)
    {
        if (nums[r]==0) nbOfZeros++;

        while (nbOfZeros>k)
        {
            if (nums[l]==0) nbOfZeros--;
            l++;
        }
        int currWindowLen=r-l+1;
        bestWindowLen=bestR-bestL+1;
        if (currWindowLen>bestWindowLen)
        {
            bestL=l;
            bestR=r;
        }

    }
    vector<int> res;
    for (int i = bestL; i <=bestR; ++i)
    {
        res.push_back(i);
    }
    return res;
}