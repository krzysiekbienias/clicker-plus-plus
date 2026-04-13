#include "std_aliases.hpp"

using namespace stl;


vector<char> minimumCharactersForWords(const vector<string>& words) {
    unordered_map<char,int> globalMaxMap;
    unordered_map<char,int> wordMap;
    for (const string & word:words) {
        wordMap.clear();
        for (char ch:word)
            wordMap[ch]++;
        for (auto & [ch,count]:wordMap) {
            globalMaxMap[ch]=std::max(globalMaxMap[ch],count);
        }
    }
    vector<char> result;
    for (auto & [ch,count]:globalMaxMap) {
        result.insert(result.end(),count,ch);
    }
    return result;
}