#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

string longestCommonPrefix(vector<string>& strs)
{   if (strs.empty() ||strs[0]=="") return "";
    int minSize = INT_MAX;
    int patternIdx = 0;
    for (int i = 0; i < strs.size(); i++)
    {
        if (minSize > strs[i].size())
        {
            int tempSize = strs[i].size();
            minSize = tempSize;
            patternIdx = i;
        }
    }
    string pattern = strs[patternIdx];
    strs.erase(strs.begin() + patternIdx);
    vector<int> v;
    bool atLeastOneCommon=false;
    int maxIdx = -1;
    if (strs.empty()) return pattern;
    for (string el : strs)
    {   atLeastOneCommon=false;
        for (int i = 0; i < pattern.size(); ++i)
        {
            if (el[i] == pattern[i])
            {
                atLeastOneCommon=true ;
                maxIdx = i;
            }

            else
            {
                break;
            }
        }
        v.push_back(maxIdx);

    }
    int cutoff=*min_element(v.begin(),v.end());
    if (!atLeastOneCommon) return "";
    return pattern.substr(0, cutoff+1);
}
