

#include "std_aliases.hpp"

using namespace stl;

//leetcode 17
long long countVowels(string word) {
    long long sum=0;
    vector<string> subsequence;
    for (size_t i=0;i<word.size();++i) {
        for (size_t len=1;i+len<=word.size();++len) {
            subsequence.emplace_back(word.substr(i,len));

        }
    }
    for (string el:subsequence){
        for (char ch:el){
            if (ch=='a' ||ch=='e'||ch=='i'||ch=='o'||ch=='u') sum++;
        }
    }
    return sum;
}


//###########
bool isVovel (char ch) {
    return ch=='a'||ch=='o'||ch=='u'||ch=='i'||ch=='e';
}

long long countVowelsOptimal(string word) {
    long long sum=0;
    for (size_t i=0;i<word.size();++i) {
        if (isVovel(word[i]))
            sum+=(i+1)*(word.size()-i);
    }
    return sum;
}