#pragma once

#include <string>
#include <vector>

enum class symbol {wild,
                    star,
                    bell,
                    shell,
                    seven,
                    cherry,
                    bar,
                    king,
                    queen,
                    jack};

inline symbol parseSymbol(std::string s)
{
    if (s=="Wild") return symbol::wild;
    if (s=="Star") return symbol::star;
    if (s=="Bell") return symbol::bell;
    if (s=="Shell") return symbol::shell;
    if (s=="Seven") return symbol::seven;
    if (s=="Cherry") return symbol::cherry;
    if (s=="Bar") return symbol::bar;
    if (s=="King") return symbol::king;
    if (s=="Queen") return symbol::queen;
    if (s=="Jack") return symbol::jack;
    throw std::invalid_argument("The symbol is not allowed");

}

unsigned fruit(const std::array<std::vector<std::string>, 3> &reels,
                const std::array<unsigned, 3> &spins);

