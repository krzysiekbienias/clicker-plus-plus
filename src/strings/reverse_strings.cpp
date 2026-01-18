#include <std_aliases.hpp>
#include <sstream>

using namespace stl;

string reverseWords(const string& str) {
    vector<string> tokens;
    string res;

    string item;
    //remove white spaces.
    int i=0;
    while (i<str.size() && str[i]==' ') {
        i++;
    }
    string noSpaceString(str.begin()+i,str.end());

    while (!noSpaceString.empty() && noSpaceString.back()==' ') {
        noSpaceString.pop_back();
    }
    std::stringstream ss(noSpaceString);
    while (std::getline(ss,item,' ')) {
        //push for tokens only if is not empty
        if (!item.empty())
        tokens.push_back(item);
    }
    if (tokens.size()==1) {
        return tokens[0];
    }
    std::reverse(tokens.begin(),tokens.end());
    for (int i=0;i<tokens.size();++i){
        if (i>0) res+=' ';
            res+=tokens[i];
        }
    return res;
    }
