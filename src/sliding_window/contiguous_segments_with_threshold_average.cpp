#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;


// Implement your logic here.
int contiguous_segments_with_threshold_average(const std::vector<int> &arr, int k, int threshold) {
    int n=arr.size();
    int res=0;
    int l=0;
    int target=threshold*k;
    //first window sum
    int windowSum=0;
    for (int i = 0; i<k ; ++i)
    {
        windowSum+=arr[i];
    }
    if (windowSum>=target)
    {
        res++;
    }
    for (int i = k; i < n; ++i)
    {
        windowSum-=arr[i-k];
        windowSum+=arr[i];
        if (windowSum>=target)
        {
            res++;
        }
    }
    return res;
}