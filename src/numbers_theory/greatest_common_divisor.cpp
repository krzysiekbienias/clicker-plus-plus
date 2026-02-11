#include <std_aliases.hpp>

int gcdRecursive(int a, int b) {
    if (b==0) return a;
    int r=a%b;
    return gcdRecursive(b,r);
}

int gcdIterative(int a, int b) {
    int gcd=1;
    for (int i=1;i<=std::min(a,b);++i) {
        if (a%i==0 && b%i==0) gcd=i;
    }
    return gcd;
}

int gcdIterativeEuclides(int a, int b) {
    while (b>0) {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}