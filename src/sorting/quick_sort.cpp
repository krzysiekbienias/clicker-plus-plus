
#include <vector>
#include "sorting/quick_sort.hpp"

static void quickSortHelper(std::vector<int>& arr,int startIdx,int endIdx)
{   int pivotIdx=startIdx;
    int leftIdx=startIdx+1;
    int rightIdx=endIdx;
    if (startIdx>=endIdx)
    {
        return;
    }
    while (leftIdx<=rightIdx)
    {
        if (arr[leftIdx]>arr[pivotIdx] && arr[rightIdx]<arr[pivotIdx])
        {
        std::swap(arr[leftIdx],arr[rightIdx]);
        }
        if (arr[leftIdx]<=arr[pivotIdx])
        {
            leftIdx++;
        }
        if (arr[rightIdx]>=arr[pivotIdx])
        {
            rightIdx--;
        }

    }
    std::swap(arr[pivotIdx],arr[rightIdx]);//at this moment arr[pivotIdx] is in the correct place
    //now right indx is like pointer index
    bool leftSubarraySmaller=(rightIdx-1-startIdx<endIdx-(rightIdx+1));
    if (leftSubarraySmaller)
    {
        quickSortHelper(arr,startIdx,rightIdx-1);
        quickSortHelper(arr,rightIdx+1,endIdx);
    }
    else
    {
        quickSortHelper(arr,rightIdx+1,endIdx);
        quickSortHelper(arr,startIdx,rightIdx-1);
    }

}

std::vector<int> quickSort(std::vector<int>&arr){
    if (arr.empty()) return {};
    quickSortHelper(arr, 0, arr.size()-1);
    return arr;
}

