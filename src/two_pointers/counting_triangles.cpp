#include "std_aliases.hpp"

using namespace stl;

int nTriangles(vector<int> &A) {
    std::sort(A.begin(),A.end());
    const long long MOD =1'000'000'007;
    long long ans=0;
    int n=(int)A.size();
    for (int k=n-1;k>=2;k--) {
        int i=0,j=k-1;
        while (i<j) {
            ll sumPerTriangle=(ll)A[i]+A[j];
            if (sumPerTriangle>A[k]) {
                ans+=j-i;
                ans%=MOD;
                --j;
            }
            else ++i;

        }
    }
    return (int)ans;
}

int nTrianglesRobust(vector<int> &A) {
    std::sort(A.begin(),A.end());
    int first=std::lower_bound(A.begin(),A.end(),1)-A.begin();
    const long long MOD =1'000'000'007;
    long long ans=0;
    int n=(int)A.size();
    for (int k=n-1;k>=first+2;k--) {
        int i=first,j=k-1;
        while (i<j) {
            ll sumPerTriangle=(ll)A[i]+A[j];
            if (sumPerTriangle>A[k]) {
                ans+=j-i;
                ans%=MOD;
                --j;
            }
            else ++i;

        }
    }
    return (int)ans;
}