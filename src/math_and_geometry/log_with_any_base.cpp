#include "std_aliases.hpp"

//Apply change base formula in logarithm
double logAnyBase(double a,double b) {
    if (a<=0)throw std::domain_error("a must be > 0");
    if (b<=0 || b==1) throw std::domain_error("base must be > 0 and != 1");
    return std::log(a)/log(b);
}