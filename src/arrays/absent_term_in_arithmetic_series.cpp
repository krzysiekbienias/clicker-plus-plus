#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
int missingNumberInArithmetic(std::vector<int> &arr)
{   int missingIndex=0;
    int n=arr.size();
    int r=arr[1]-arr[0];
    int diff =0;
    int missingNumb=0;
    for (int i=2;i<arr.size();i++){
        diff=arr[i]-arr[i-1];
        if (diff!=r)
        {
            missingIndex=i;
        }

    }
    if ((missingIndex!=0) && (missingIndex!=n-1))
    {
        if (r<0) missingNumb=arr[missingIndex-1]-r;
        if (r>0) missingNumb=arr[missingIndex-1]+r;
    }

    if ((missingIndex==0) || (missingIndex==n-1))
    {
        r=diff;
        if (r<0) missingNumb=arr[missingIndex-1]-r;
        if (r>0) missingNumb=arr[missingIndex-1]+r;
    }


    return missingNumb;
}