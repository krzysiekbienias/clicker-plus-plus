#include "std_aliases.hpp"
#include "utils/print_utils.hpp"
#include "utils/print_utils_templates.hpp"

using namespace stl;
using namespace io;
//from book
vector<string> trendingHashtagAnalysis(vector<string>hashtags,int k) {
    //count frequency
    unordered_map <string,int> hashMap;
    for (string str:hashtags)
        hashMap[str]++;
    print_utils::printUnorderedMap(hashMap);

    //define min-heap becasue we are looking for most frequent
    auto compare=[&hashMap](const string & a,const string &b) {
        return hashMap[a]>hashMap[b];
    };

    priority_queue<string,vector<string>,decltype(compare)> minHeap(compare);

    //DEBUG push elements to the heap
    for (const auto & pair : hashMap) {
        minHeap.push(pair.first);
    }
    //DEBUG dump to vector do copy to not distroy orginal
    vector<string> dump;
    auto heapCopy=minHeap;

    while (!heapCopy.empty()) {
        string top=heapCopy.top();
        dump.push_back(top);
        heapCopy.pop();
    }
    print_utils::printVector(dump);
    //END DEBUG

    for (const auto & pair : hashMap) {
        minHeap.push(pair.first);
        if (minHeap.size()>k)
            minHeap.pop();
    }

    //build vector results
    vector<string> res(k);
    for (int i=k-1;i>=0;--i) {
        if (!minHeap.empty()) {
            res[i]=minHeap.top();
            minHeap.pop();
        }
    }
    return res;

}