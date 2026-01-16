#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.

int bestSeat(const std::vector<int>& seats)
{
    int left = 0;
    int right = 0;
    int bestSeat = -1;
    int maxSpace = 0;
    int n = seats.size();
    int availableSpace = 0;
    while (left < n)
    {
        right = left + 1;
        while (right < n and seats[right] == 0) right++;
        availableSpace = right - left - 1;
        if (availableSpace > maxSpace)
        {
            bestSeat = (right + left) / 2;
            maxSpace = availableSpace;
        }
        //we start with new seats range
        left = right;
    }
    return bestSeat;
}
