#include "arrays/kids_with_greatest_number_of_candies.hpp"

// Implement your logic here.

std::vector<bool> kidsWithCandies(const std::vector<int>& candies, int extraCandies) {
    // 1) Jednorazowo bierzemy maksimum
    int mx = *max_element(candies.begin(), candies.end());

    std::vector<bool> res;
    res.reserve(candies.size());

    // 2) Jedno przejście i porównania
    //    (rzut do int64_t jeśli obawiasz się overflow przy dodawaniu)
    int64_t extra = extraCandies;
    for (int c : candies) {
        res.push_back(int64_t(c) + extra >= mx); //zauwaz ze to doklada boola 🧠
    }
    return res;
}
