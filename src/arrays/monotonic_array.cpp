#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

static bool isNonDecreasing(const std::vector<int>& arr)
{   int n=arr.size();
    for (int i=1;i<n;++i)
    {
        if (arr[i-1]>arr[i]) return false;

    }
    return true;
}

static bool isNonIncreasing(const std::vector<int>& arr)
{   int n=arr.size();
    for (int i=1;i<n;++i)
    {
        if (arr[i]>arr[i-1]) return false;
    }
    return true;

}

bool isMonotonic(std::vector<int> arr)
{
    if (arr.size()<=1) return true;
    return  isNonDecreasing(arr) || isNonIncreasing(arr);

}

