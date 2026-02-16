#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
int headerToNumber(string s)
{
    long long x = 0; // bezpieczny akumulator
    for (char ch : s) {
        int d = (toupper((unsigned char)ch) - 'A') + 1; // A=1..Z=26
        // opcjonalna osłona na overflow dla int32
        if (x > (INT_MAX - d) / 26) throw std::overflow_error("beyond scope");
        x = x * 26 + d;
    }
    // jeśli chcesz twardo pilnować int32:
    // if (x > INT_MAX) throw overflow_error("too large");
    return static_cast<int>(x);
}