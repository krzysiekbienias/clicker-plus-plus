#include "searching/index_equal_value.hpp"
#include <vector>

// Implement your index_equal_value logic here.
int indexEqualsValueLinear(const std::vector<int>& array){
    for (int i=0;i<array.size();++i){
        if(i==array[i]){
            return i;
        }
        
    }
    return -1;
    
}

int indexEqualValue(const std::vector<int>& array)
{
    int res=-1;
    int n=array.size();
    int left=0;
    int right = n-1;

    while (left<=right)
    {
        int mid=left+(right-left)/2;
        if (mid==array[mid])
        {
            res=mid;
            right=mid-1;

        }
        else if (array[mid]<mid)
        {
            left=mid+1;
        }

        else if (array[mid]>mid)
        {
            right=mid-1;
        }

    }
    return res;
}