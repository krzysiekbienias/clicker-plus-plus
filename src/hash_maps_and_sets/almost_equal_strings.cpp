#include "std_aliases.hpp"

using namespace stl;

bool areAlmostEqual(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    //we already have |s1|==|s2|
    vector<int> diff;
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i])
            diff.push_back(i);
    }
    if (diff.size() == 0)
        return true;
    else if (diff.size() == 1 || diff.size() > 2)
        return false;
    //when diff.size()==2
    return s1[diff[0]] == s2[diff[1]] && s2[diff[0]] == s1[diff[1]];
}
