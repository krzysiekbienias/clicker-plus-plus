
#include "std_aliases.hpp"
using namespace stl;

int minimumWaitingTime(vector<int> queries){
    int n= queries.size();
    int totalWaitingTime=0;
    int prefSum=0;
    std::sort(queries.begin(),queries.end());
    for (int i=0;i<n;++i){
        totalWaitingTime+=prefSum;
        prefSum+=queries[i];
    }
    return totalWaitingTime;

}




