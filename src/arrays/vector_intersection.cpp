#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

std::vector<int> vectorIntersection(std::vector<int> a, std::vector<int> b) {

    std::vector<int> res;
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            res.push_back(a[i]);
            ++i; ++j;
        } else if (a[i] < b[j]) {
            ++i;
        } else {
            ++j;
        }
    }
    return res; // multizbiór: 3 pojawi się min(liczba_3_w_a, liczba_3_w_b) razy
}