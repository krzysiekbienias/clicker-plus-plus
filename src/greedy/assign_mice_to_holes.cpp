#pragma once

#include <std_aliases.hpp>
using namespace stl;

int miceToWholes(vector<int> &mice, vector<int> &holes) {
    sort(mice.begin(),mice.end());
    sort(holes.begin(),holes.end());
    int n =mice.size();
    int maxDis=0;
    for (int i=0;i<n;i++){
        int localDist=abs(holes[i]-mice[i]);
        maxDis=std::max(maxDis,localDist);
    }
    return maxDis;
}