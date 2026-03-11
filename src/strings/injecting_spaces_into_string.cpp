#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

std::string addSpaces(std::string s, std::vector<int> &spaces) {
    int i=0;
    int j=0;
    std:: string res="";
    res.reserve(s.size()+spaces.size());

    while (i<s.size())
    {
        if (j<spaces.size() && spaces[j]==i)
        {
            res+=" ";
            j++;
        }
        res+=s[i];
        i++;
    }
    return res;
}

