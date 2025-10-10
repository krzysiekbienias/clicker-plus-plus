#include <std_aliases.hpp>

using namespace stl;

vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
    unordered_map<int,int> idIdxMap;
    int i=0;
    for (int id : order) {
        idIdxMap[id]=++i;
    }

    sort(friends.begin(),friends.end(),[&](int a,int b)->bool {return idIdxMap[a]<idIdxMap[b];});
    return friends;
}

