#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your container_with_most_water logic here.

int containerWithMostWatter(const vector<int> &height) {
    if (height.empty()) return 0;
    int left=0;
    int right=height.size()-1;
    int max_area=0;

    int width=right-left;
    while (left<right)
    {
        max_area=std::max(max_area,std::min(height[left],height[right])*width);
        if (height[left]<height[right])
        {
            left++;
            width--;
        }
        else
        {
            right--;
            width--;
        }


    }
    return max_area;
}