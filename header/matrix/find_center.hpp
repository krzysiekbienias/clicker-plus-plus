#pragma once

#include <string>
#include <vector>

using opt_int_t = std::optional<int>;
using matrix_t = std::vector<std::vector<int>>;


opt_int_t center(const matrix_t& mat);