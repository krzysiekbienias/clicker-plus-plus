#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
int multiples3Or5(int number)
{
    if(number<=0)
        return 0;
    int res = 0;
    for(int i=1; i<number; ++i) {
        if(i%3==0 || i%5==0)
            res += i;
    }
    return res;
}