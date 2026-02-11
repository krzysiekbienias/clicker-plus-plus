#include "sorting/bubble_sort.hpp"
#include <iostream>


// Implement your bubble_sort logic here.
std::vector<int> bubbleSortDebug(std::vector<int>& array){
    int n=array.size();
    int totalPasses=0; //helper to measure small optimisation
    int savedPasses=0;
    for (int i=n-1; i>0;--i){//<------ we shring from the end
        bool isSorted=true; //optymistic
        totalPasses++;
        for (int j=0;j<i;++j){
            if (array[j]>array[j+1]) {
                std::swap(array[j], array[j+1]);
                isSorted=false; //out of order pair has been found;
            }
        }
        if(isSorted){
            savedPasses=i;
            std::cout<<"[Optimized] Early exit after"<<totalPasses<<" passes. Saved "<<savedPasses<<" unnecessary passes.\n";//DEBUG
            break;
            
        }
    }
    if(savedPasses==0){
        std::cout << "[Full Run] No early exit. Completed " << totalPasses << " passes.\n";// DEBUG
    }
    return array;
}

std::vector<int> bubbleSort(std::vector<int> nums) {
    int n=nums.size();
    for(int i=n-1;i>=0;--i){
        bool isSorted=true;
        for (int j=0;j<i;j++){
            if(nums[j]>nums[j+1]){
                std::swap(nums[j],nums[j+1]);
                isSorted=false;

            }
        }
        if (isSorted)
            break;
    }
    return nums;

}