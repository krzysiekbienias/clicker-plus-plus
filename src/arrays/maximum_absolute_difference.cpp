#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

 i64 maxAbsoluteDiffBF(const vector<int>& nums)
{   //f(i,j)=|A[i]-A[j]|+|i-j| the smallest possible is 0
    int n=nums.size();
    i64 best=0; //
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<i;++j)
        {
            i64 x=nums[i]-nums[j];
            i64 y=i-j;
            i64 cand=std::max({x+y,x-y,-x+y,-x-y});

            best=std::max(cand,best);
        }
    }
     return best;
}

i64 maxAbsoluteDiff(const vector<int>& A)
 {   //f(i,j)=|A[i]-A[j]|+|i-j| the smallest possible is 0
     int n=A.size();
     int a0=A[0];
     int i0=0;
     //we need to initialize some how if we do not use limits
     int min1=a0+i0, max1=a0+i0;
     int min2=a0-i0, max2=a0-i0;
     int min3=-a0+i0, max3=-a0+i0;
     int min4=-a0-i0, max4=-a0-i0;

     for (int i=1;i<n;++i)
     {
         int ai=A[i];

         int v1=ai+i;
         int v2=ai-i;
         int v3=-ai+i;
         int v4=-ai-i;

         min1=std::min(min1,v1),max1=std::max(max1,v1);
         min2=std::min(min2,v2),max2=std::max(max2,v2);
         min3=std::min(min3,v3),max3=std::max(max3,v3);
         min4=std::min(min4,v4),max4=std::max(max4,v4);

     }
     int ans1=max1-min1;
     int ans2=max2-min2;
     int ans3=max3-min3;
     int ans4=max4-min4;

     return std::max({ans1,ans2,ans3,ans4});

 }