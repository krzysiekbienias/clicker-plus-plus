#include <std_aliases.hpp>
using namespace stl;

int addNumbers(int a,int b) {
    while (b!=0) {
        int carry=(a&b)<<1;
        a=a^b; //bits without carry
        b=carry;
    }
    return a;
}