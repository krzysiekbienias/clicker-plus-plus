#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

std::string stringShift(std::string s, const std::vector<std::vector<int>> &shift)
{
    std::string res=s;
    int n=s.size();
    for (vector<int> item:shift)
    {
        int direction=item[0];
        int value=item[1]%n;
        if (direction==0)
        {
            string pref=res.substr(0,value);
            res=res.substr(value)+pref;
        }

        else
        {
            string suff=res.substr(n-value);
            res=suff+res.substr(0,n-value);
        }
    }
    return res;
}
// Implement your logic here.
