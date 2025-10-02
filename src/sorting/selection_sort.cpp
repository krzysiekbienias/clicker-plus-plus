#include<vector>
#include <iostream>

// Implement your selection_sort logic here.
std::vector<int> selectionSorting(std::vector<int>& array){
    // 1. empty arr
    if (array.empty()) return {};
    int startIdx=0;
    //until second to last
    while (startIdx<array.size()-1) {
        int smallestIdx=startIdx;

        for (int i=smallestIdx+1;i<array.size();++i) {
            //block dedicated to find smallest index per suffix array
            if (array[smallestIdx]>array[i]) {
                smallestIdx=i;
            }

        }
        std::swap(array[smallestIdx],array[startIdx]);
        startIdx++;
    }
    return array;
}
