#include <unordered_map>

// Implement your nth_fibbonaci logic here.
int nthFibbonaci(int n,std::unordered_map<int,int>& lookup){
    if(lookup.count(n)) return lookup[n];
    
    if (n==0) return 0;
    if (n==1) return 1;
    
    lookup[n]=nthFibbonaci(n-1, lookup)+nthFibbonaci(n-2, lookup);
    return lookup[n];
}


//If is required to pass only one argument we may use overlopading function as presented below.
int nthFibbonaci(int n){
    std::unordered_map<int, int> lookup;
    return nthFibbonaci(n, lookup);
}
//interviewBit not the fastest
int nthFibWithMod(int A) {
    constexpr int MOD=1'000'000'007;
    if (A<=0) return 0;
    if (A==1 || A==2) {
        return 1;
    }
    long long a=1,b=1;
    for (int i=3;i<=A;++i) {
        long long c=(a+b)%MOD;
        a=b;
        b=c;
    }
    return (int)b;

}