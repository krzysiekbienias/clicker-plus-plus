#include <vector>

int nextIdx(int currentIdx,std::vector<int>arr){
    int n=(int)arr.size();
    int destinationIdx=(currentIdx+arr[currentIdx])%n;

    if(destinationIdx<0) destinationIdx+=n;
    return destinationIdx;

}

bool hasSingleCycle(std::vector<int> array){
    int n=(int)array.size();
    int startIdx=0;
    int visitedCount=0;
    while (visitedCount<n){
        //if happen that we return to start index before we vist all indexes. (vertices in Graph)
        if(visitedCount>0 && startIdx==0) return false;
        startIdx= nextIdx(startIdx,array);
        ++visitedCount;
    }

    return startIdx == 0;

}

