#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

std::string bracketKeyInterpreter(std::string s, std::vector<std::vector<std::string>> &knowledge) {
    string res;
    string currentKey;
    bool isInsideBracket=false;
    unordered_map<string,string> buff;

    for (const auto& x:knowledge)
    {
        buff[x[0]]=x[1];
    }
    int n=s.size();
    for (int i = 0; i < n; ++i)
    {
        if (s[i]=='(')
        {
            isInsideBracket=true;
        }
        else if (s[i]==')')
        {
            auto it=buff.find(currentKey);
            if (it!=buff.end())
            {
                res+=it->second;
            }
            else
            {
                res+='?';
            }
            currentKey.clear();
            isInsideBracket=false;
        }
        else if (isInsideBracket)
        {
            currentKey+=s[i];
        }
        else
        {
            res+=s[i];
        }
    }
    return res;
}

