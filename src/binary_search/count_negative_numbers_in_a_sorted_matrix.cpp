#include "binary_search/count_negative_numbers_in_a_sorted_matrix.hpp"
#include <vector>
#include <string>

using std::vector;
using std::string;

int countNegatives(vector<vector<int>> &grid) {
    int res = 0;
    for (auto v : grid) {
      auto it = upper_bound(v.begin(), v.end(), 0, std::greater<int>());
      res += v.end() - it;
    }
    return res;
  }
