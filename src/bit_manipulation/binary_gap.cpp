

#include <algorithm>

int binaryGap(int n) {
    int maxGap=0;
    int prev=-1; // the index of previous 1 cannot be 0 because we may have 1 at index 0 (from right)
    int i=0; //index of the current bit (for traversing)
    while (n>0) {
        if (n&1) {
            if (prev!=-1)
                maxGap=std::max(maxGap,i-prev);
            prev=i;
        }
        n>>=1; //move right and update n
        ++i;
    }
    return maxGap;

}
