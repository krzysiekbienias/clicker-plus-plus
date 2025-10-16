#include "std_aliases.hpp"

using namespace stl;


vector<char> minimumCharactersForWords(vector<string> words) {
    unordered_map<char,int> globalMaxMap;
    for (string & word:words) {
        unordered_map<char,int> wordMap;
        for (char ch:word)
            wordMap[ch]++;
        for (auto & [ch,count]:wordMap) {
            auto it =globalMaxMap.find(ch);
            if (it==globalMaxMap.end()) globalMaxMap[ch]=count; //ch first time in globalMaxMap
            else it->second=std::max(it->second,count);
        }
    }
    vector<char> result;
    for (auto & [ch,count]:globalMaxMap) {
        result.insert(result.end(),count,ch);
    }
    return result;

}