#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;
#include "numbers_theory/greatest_common_divisor.hpp"


// Implement your logic here.
int restaurant(int l, int b)

{
    if (l<=0 or b<=0)
    {
        return 0;
    }
    int rectangleArea = l * b;
    int gcd = gcdRecursive(l, b);
    int squareArea = gcd * gcd;
    int squaresNumber = rectangleArea / squareArea;
    return squaresNumber;
}
