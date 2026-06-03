#pragma once
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

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

int calPoints(const std::vector<std::string>& operations);