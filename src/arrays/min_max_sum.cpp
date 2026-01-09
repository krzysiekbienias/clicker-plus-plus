#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

int minMaxSumBF(vector<int>& arr)
{
    sort(arr.begin(),arr.end());
    return arr[0]+arr[arr.size()-1];
}

int minMaxSum(vector<int>& arr)
{
    int minEl=arr[0];
    int maxEl=arr[0];
    for (int i=1;i<arr.size();++i)
    {
        if (arr[i]<minEl) minEl=arr[i];
        if (arr[i]>maxEl) maxEl=arr[i];
    }
    return minEl+maxEl;
}

