#include<std_aliases.hpp>
#include <backtracking/all_possible_combinations.hpp>
using namespace stl;


vector<string> specialStrings(const vector<string> &choicesInput) {
    vector<string> res;
    if (choicesInput.empty()) return {};
    string buffer;
    for (const auto &s: choicesInput)
        if (s.empty()) return {};
    //to make sure that strings are generated in lexicographic order, we sort chars in each choicesInput[i]
    vector<string> choices = choicesInput;
    for (auto &s: choices) {
        sort(s.begin(), s.end());
    }
    buffer.reserve(choices.size());
    backtrackSpecialStr(choices, 0, buffer, res);

    return res;
}

void backtrackSpecialStr(const vector<string> &choices, int idx, string &buffer, vector<string> &res) {
    int n = choices.size();
    //base case
    if (idx == n) {
        res.push_back(buffer);
        return;
    }
    for (char c: choices[idx]) {
        buffer.push_back(c);
        backtrackSpecialStr(choices, idx + 1, buffer, res);
        buffer.pop_back();
    }
}
