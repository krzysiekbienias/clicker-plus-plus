#include <std_aliases.hpp>


using namespace stl;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    auto l=flowerbed.size();
    for (int i=0;i<l && n>0; ) {
        if (flowerbed[i]==1) {
            i+=2;
            continue;
        }
        int left =(i==0?0:flowerbed[i-1]);
        int right =(i==l-1?0:flowerbed[i+1]);
        if (left == 0 && right ==0) {
            flowerbed[i]=1;
            --n;
            i+=2;
        }
        else ++i;

    }
    return n<=0;
}