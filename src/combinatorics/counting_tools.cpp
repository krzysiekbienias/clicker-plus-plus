#include <std_aliases.hpp>
#include <numeric>


using namespace stl;
using namespace io;
using namespace str;

u64 nCk(int n, int k)
{
    u64 res = 1;
    for (int i = 1; i <= k; i++)
    {
        int nom = (n - k + i);
        int denom = i;
        //first reduce
        int gcd1 = std::gcd(nom, denom);
        nom /= gcd1;
        denom /= gcd1;
        //second reduce
        int gcd2 = std::gcd(res, denom);
        res/=gcd2;
        denom /= gcd2;
        //now denom should be equal 1
        res *= nom;
    }
    return res;
}
