#include "std_aliases.hpp"

using namespace stl;


vector<vector<int>> powerset(vector<int> array) {
    size_t n=array.size();
    vector<vector<int>> allSubsets;

    for (int mask =0 ;mask<1<<n;mask++) {
        vector<int> subset;
        for (int i=0;i<n;++i) {
            if (mask & (1<<i)) //if not equal 0 (true) intersections then take it
                subset.push_back(array[i]);

        }
        allSubsets.push_back(std::move(subset));

    }
    return allSubsets;
}