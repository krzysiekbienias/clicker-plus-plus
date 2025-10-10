#include <vector>
#include "two_pointers/sweet_and_savory.hpp"

std::vector<int> sweetAndSavory(std::vector<int> dishes, int target) {
    std::sort(dishes.begin(), dishes.end());
    int l = 0, r = (int)dishes.size() - 1;
    int bestLeft = -1, bestRight = -1;
    int bestGap = INT_MAX;

    while (l < r && dishes[l] < 0 && dishes[r] > 0) {
        int sum = dishes[l] + dishes[r];
        if (sum > target) {
            // too savory → reduce savory
            --r;
        } else {
            // valid candidate (≤ target) → consider and try to get closer by making sweet less negative
            int gap = target - sum;                // what we want to minimize
            if (gap < bestGap) {
                bestGap = gap;
                bestLeft = l;
                bestRight = r;
            }
            ++l; // move toward less negative sweet to increase sum
        }
    }

    if (bestGap == INT_MAX) return {0, 0};
    return {dishes[bestLeft], dishes[bestRight]};
}