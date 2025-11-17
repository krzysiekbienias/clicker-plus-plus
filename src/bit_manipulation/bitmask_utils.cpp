
#include <std_aliases.hpp>
#include "math_and_geometry/log_with_any_base.hpp"

std::string toBinTrim(unsigned mask) {
    if (mask == 0) return "0";
    std::string s = std::bitset<64>(mask).to_string();
    // utnij wiodące zera
    auto pos = s.find('1');
    return s.substr(pos);
}

std::vector<int> maskToIndices(uint64_t mask) {
    std::vector<int> out;
    while (mask) {
        // wyciągnij najniższy ustawiony bit (LSB)
        uint64_t lsb = mask & -mask;
        int i = __builtin_ctzll(mask);   // liczba zer na końcu (pozycja LSB)
        out.push_back(i);
        mask ^= lsb; // wyczyść ten bit
    }
    return out;
}

int numberOfDigits(int x, int b) {
    double l=logAnyBase(x,b);
    return std::floor(l)+1;

}