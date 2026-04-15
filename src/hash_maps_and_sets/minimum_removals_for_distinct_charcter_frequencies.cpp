#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

int minDeletionsForDistinctCharactersFreq(std::string s)
{   unordered_map<char,int> charFreq;
    unordered_set<int> seen;
    int deletions=0;
    for (char ch:s)
    {
        charFreq[ch]++;
    }
    for (auto& [ch,freq]:charFreq)
    {
        while (freq>0 && seen.contains(freq))
        {
            freq--;
            deletions++;
        }
        if (freq>0)
        {
            seen.insert(freq);
        }
    }
    return deletions;
}
