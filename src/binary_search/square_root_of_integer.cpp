#include <binary_search/square_root_of_integer.hpp>

int mySqrt(int x) {
    int ans=-1;
    int left=0;
    int right=x;
    while(left<=right){
      long long mid=left+(right-left)/2;
      if(mid*mid<=x){
        ans=mid;
        left=mid+1;

      }
      else{
        right=mid-1;
      }
      
    }
    return ans;
    }