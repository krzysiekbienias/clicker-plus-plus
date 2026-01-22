#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
std::vector<int> showBitsModulo(int n)
{
    vector<int> res(32);
    for (int i = 0; i < 32; i++)
    {
        int bit = n % 2;
        res[32 - 1 - i] = bit;
        n /= 2;
        if (n == 0) break;
    }
    return res;
}

std::vector<int> showBits(int n)
{
    vector<int> res(32);
    std::uint32_t u = static_cast<std::uint32_t>(n);

    for (int i = 0; i < 32; i++)
    {
        res[31 - i] = static_cast<int>(u & 1);
        u >>= 1;
    }
    return res;
}
