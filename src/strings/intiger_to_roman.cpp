#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

std::string intToRoman(int num) {
    vector<Pair<int, string> > mapping = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    string romanNumber = "";
    for (int i = 0; i < mapping.size() && num > 0; ++i) {
        while (mapping[i].first <= num) {
            num -= mapping[i].first;
            romanNumber += mapping[i].second;
        }
    }
    return romanNumber;
}
