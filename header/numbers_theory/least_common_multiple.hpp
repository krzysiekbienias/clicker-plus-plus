#include <numbers_theory/greatest_common_divisor.hpp>

int leastCommonMultiple(int a,int b) {
    int numerator=a*b;
    int denom=findGCD(a,b);
    return numerator/denom;
}
