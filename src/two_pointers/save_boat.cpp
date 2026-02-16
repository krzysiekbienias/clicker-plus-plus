#include "std_aliases.hpp"


using namespace stl;


int rescueBoats(vector<int> people, int limit)
{
    int n = people.size();
    int boats = 0;
    std::sort(people.begin(), people.end());
    int lightPointer = 0;
    int heavyPointer = n - 1;

    while (lightPointer <= heavyPointer)
    {
        if (people[lightPointer] + people[heavyPointer] <= limit)
        {
            lightPointer++;
            heavyPointer--;
            boats++;
        }
        else
        {
            boats++;
            heavyPointer--;
        }
    }
    return boats;
}
