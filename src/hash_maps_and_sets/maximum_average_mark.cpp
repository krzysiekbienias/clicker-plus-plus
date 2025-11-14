#include "std_aliases.hpp"

using namespace stl;

int highestScore(vector<vector<string> > &A) {
    unordered_map<string,pair<int,int>> cache;
    for (const auto& x:A) {
        if (cache.count(x[0])==0) {
            int tempValue=stoi(x[1]);
            cache[x[0]]={tempValue,1};
        }

        else {
            auto &p=cache[x[0]];
            p.first+=stoi(x[1]);
            ++p.second;
        }
    }
    int bestAverage=0;
    for (auto [k,p]:cache) {
        int tempAverage=cache[k].first/cache[k].second;
        bestAverage=std::max(tempAverage,bestAverage);
    }

    return  bestAverage;
    }
