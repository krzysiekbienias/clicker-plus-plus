#pragma once
#include <sstream>

#include "std_aliases.hpp"

using namespace stl;
using namespace str;

vector<string> tokenize(const string &s, char delimiter = ' ') {
    vector<string> tokens;
    istringstream iss(s);
    string item;
    vector<string> out;
    while (getline(iss, item, delimiter)) {
        out.push_back(item);
    }
    return out;
}

int stringToInt(const string &str) {
    if (str.empty()) return 0;
    int n = str.size();
    int64_t res = 0;
    int i = 0;
    while (i < n and str[i] == ' ') {
        i++;
    }
    int sign = 1;
    if (i < n) {
        if (str[i] == '-') {
            sign = -1;
            i++;
        } else if (str[i] == '+')
            i++;
    }
    for (; i < n; ++i) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != ' ') {
            throw std::invalid_argument("We cannot convert non digit");
        }
        if (str[i] == ' ')
            continue;
        res = res * 10 + str[i] - '0';
    }
    int64_t signedVal = sign * res;
    if (signedVal > INT_MAX) throw std::out_of_range("String is beyond int scope");
    if (signedVal < INT_MIN) throw std::out_of_range("String is beyond int scope");
    return signedVal;
}
