#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
int trailingZeros(int n)
{
    int cnt=0;
    while (n>0)
    {
        int lastBit=n&1;
        if (lastBit==0) cnt++;

        else
        {
            break;
        }
        n>>=1;
    }
    return cnt;

}