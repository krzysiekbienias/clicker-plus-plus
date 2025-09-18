#pragma once
#include<vector>
#include<string>

inline
bool isNumber(const std::string& s) {
    if (s.empty()) return false;
    size_t startIdx=0;
    if (s[0]=='-') {
        if (s.size()==1) return false;
        startIdx=1;
    }

    return std::all_of(s.begin()+startIdx,s.end(),::isdigit);
}

int calPoints(std::vector<std::string>& operations);