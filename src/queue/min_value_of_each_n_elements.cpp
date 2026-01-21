#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

std::vector<int> minValue(const std::vector<int>& arr, std::size_t k)
{
    int len=arr.size();
    vector<int> result;
    for (int i = 0; i+k <= len; ++i)
    {
        int mn =*std::min_element(arr.begin()+i, arr.begin()+i+k);
        result.push_back(mn);
    }
    return result;
}// Implement your logic here.
