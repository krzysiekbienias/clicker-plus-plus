#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
long long rearrangementForMinimalSignedValue(long long num) {
    long long rearranged=0;
    std::string s_num=std::to_string(num);
    if (s_num[0]=='-')
    {   s_num.erase(s_num.begin());
        sort(s_num.rbegin(),s_num.rend());
        rearranged=-stoll(s_num);
        return rearranged;
    }
    {
        std::sort(s_num.begin(),s_num.end());
    }
    for (int i = 0; i < s_num.size(); ++i)
    {
        if (s_num[i]=='0') continue;
        else
        {
            std::swap(s_num[i],s_num[0]);
            break;
        }
    }
    rearranged= stoll(s_num);
    return rearranged;
}