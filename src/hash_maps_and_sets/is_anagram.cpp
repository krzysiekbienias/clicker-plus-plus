#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
bool isAnagram(string s, string t) {
    if(s.size()!=t.size()) return false;

    vector<int> freq(26,0);
    for (char ch : s){
        freq[ch-'a']++;
    }
    for (char ch : t){
        freq[ch-'a']--;
    }

    for (int el:freq){
        if(el!=0) return false;

    }
    return true;

}