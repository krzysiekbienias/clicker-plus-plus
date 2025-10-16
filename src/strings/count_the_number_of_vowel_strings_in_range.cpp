#include <std_aliases.hpp>
using namespace stl;

bool isVowel(char c){
    return c=='a' || c=='e' || c=='i'||c=='o'||c=='u';
}

int vowelStrings(vector<string>& words, int left, int right) {
    int res=0;

    auto isVowelString=[&](string& word){

        return (isVowel(word[0]) && word[word.size()-1]);
    };
    for (int i=left; i<=right;++i){
        string word=words[i];
        if(isVowelString(word)) res++;

    }
    return res;
}