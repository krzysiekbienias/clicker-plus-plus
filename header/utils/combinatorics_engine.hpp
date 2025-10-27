#pragma once


inline vector<string> subsequence(string str) {
    vector<string> subsequence;
    for (size_t i=0;i<str.size();++i) {
        for (size_t len=1;i+len<=str.size();++len) {
            subsequence.emplace_back(str.substr(i,len));

        }
    }
    return subsequence;

}

inline unordered_set<string> uniqueSubsequence(string str) {
    unordered_set<string> subsequence;
    for (size_t i=0;i<str.size();++i) {
        for (size_t len=1;i+len<=str.size();++len) {
            subsequence.insert(str.substr(i,len));

        }
    }
    return subsequence;
}