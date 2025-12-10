#pragma once
#include <sstream>

#include "std_aliases.hpp"

using namespace stl;
using namespace str;

vector<string> tokenize(const string& s,char delimiter=' ') {
    vector<string> tokens;
    istringstream iss(s);
    string item;
    vector<string> out;
    while (getline(iss,item,delimiter)) {
        out.push_back(item);
    }
    return out;
}