
#include<vector>

// Implement your remove_duplicates_from_sorted_array logic here.
int removeDuplicatesFromSortedArray(std::vector<int>& arr){
    int insertIndex{1};
    for (int i=1;i<arr.size();++i){
        //we skip to next index if we see a duplicate element, not enter to the if loop and go to another i
        if(arr[i]!=arr[i-1]){
            arr[insertIndex]=arr[i];
            insertIndex++;
        }
    }
    return insertIndex;
}


int removeDuplicatesFromSortedArrayTwiceAllowed(std::vector<int>& arr){
    int n=arr.size();
    if (n<=2) return n;
    int insertIndex{2}; //first two always stay
    for (int i=2;i<arr.size();++i){
        //we skip to next index if we see a duplicate element, not enter to the if loop and go to another i
        if(arr[i]!=arr[insertIndex-2]){
            arr[insertIndex]=arr[i];
            insertIndex++;
        }
    }
    return insertIndex;
}

