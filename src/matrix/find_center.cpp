#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

using opt_int_t = std::optional<int>;
using matrix_t = std::vector<std::vector<int>>;

opt_int_t center(const matrix_t& mat) {
    if (mat.empty() || mat[0].empty()) {return std::nullopt;}
    int r=mat.size(), c=mat[0].size();
    if (((r&1)==0) || ((c&1)==0))
    {
        return std::nullopt;
    }
    return mat[r/2][c/2];
}

