#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

std::vector<int> filterRestaurants(std::vector<std::vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance) {
    vector<pair<int,int>> candidates;
    vector<int> res;
    int n=restaurants.size();
    candidates.reserve(n);
    for (const auto& r:restaurants)
    {
        if ((veganFriendly==0||r[2]==1) && r[3]<=maxPrice && r[4]<=maxDistance)
        {
            candidates.push_back({r[1],r[0]});
        }
    }
    sort(candidates.rbegin(),candidates.rend());
    for (const auto &[rating,id]:candidates)
    {
        res.push_back(id);
    }
    return res;
}

