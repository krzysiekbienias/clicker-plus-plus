#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;



vector<vector<string>> semordnilap(vector<string> words) {
    unordered_set<string> seen;
    vector<vector<string>> res;
    for (string word:words)
    {   string reversed=word;
        std::reverse(reversed.begin(),reversed.end());
        if (seen.count(reversed))
        {
            res.push_back({word,reversed});
        }
        seen.insert(word);
    }
    return res;
}
