#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
int longestPeak(vector<int> arr)
{
    int n = arr.size();
    int bestLen = 0;
    for (int i = 1; i + 1 < n;)
    {
        bool isPeak = (arr[i] > arr[i - 1] && arr[i + 1] < arr[i]);
        if (!isPeak)
        {
            ++i;
        }
        else
        {
            int left = i - 2;
            while (left >= 0 && arr[left] < arr[left + 1])
            {
                left--;
            }
            int right = i + 2;
            while (right < n && arr[right] < arr[right - 1])
            {
                right++;
            }
            int localLen = (right - 1) - (left + 1) + 1;
            bestLen = std::max(localLen, bestLen);
            i = right;
        }
    }
    return bestLen;
}
