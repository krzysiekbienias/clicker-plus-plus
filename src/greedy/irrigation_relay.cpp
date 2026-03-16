#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

int wateringPlants(const std::vector<int> &plants, int capacity)
{
    int steps=0;
    int water=capacity;
    int n=plants.size();
    for (int i = 0; i < n; ++i)
    {
        if (water<plants[i])
        {
            steps+=2*i+1;
            water=capacity;
        }
        else
        {
            steps++;
        }
        water-=plants[i];
    }
    return steps;

}
