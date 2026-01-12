#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
vector<int> largestRange(vector<int>& array)
{
    if (array.empty()) return {};
    vector<int> res;
    std::sort(array.begin(), array.end());
    int maxRange = 0;
    int n = array.size();
    int start = array[0];
    for (int i = 1; i < n; ++i)
    {
        if (array[i] == array[i - 1] || array[i] == array[i - 1] + 1)continue;
        if (array[i] != array[i - 1] + 1)
        {
            //gap
            int tempRange = array[i - 1] - start + 1;
            if  (tempRange > maxRange)
            {
                maxRange = tempRange;
                res = {start, array[i - 1]};
            }
            start = array[i];
        }
    }
    int len = array.back()-start+1;
    if (len>maxRange)
    {
        res = {start, array.back()};
    }


    return res;
}
