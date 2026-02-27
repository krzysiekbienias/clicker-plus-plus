#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.

std::string getMiddle(std::string input)

{
    if (input.empty())
    {
        return "";
    }

    if (input.size()<=2)
    {
        return input;
    }
    int n=input.size();
    string res="";
    int idx=0;
    if (n%2!=0)
    {
        idx=n/2;
        res=input[idx];
        return res;
    }
    else
    {
        idx=n/2;
        res+=input[idx-1];
        res+=input[idx];
    }
    return res;

}