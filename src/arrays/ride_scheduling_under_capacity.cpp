#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

bool carPooling(const std::vector<std::vector<int>> &trips, int capacity) {
    vector<pair<int,int>> journey; //km delta
    for (vector<int>item:trips)
    {
        journey.push_back({item[1],item[0]});
        journey.push_back({item[2],-item[0]});
    }

    std::sort(journey.begin(),journey.end());
    int currentPassangers=0;
    for (std::pair<int,int> item:journey)
    {
        currentPassangers+=item.second;
        if (currentPassangers>capacity)
        {
            return false;
        }
    }
    return true;

}
