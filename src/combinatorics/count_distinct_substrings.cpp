#include "combinatorics/count_distinct_substrings.hpp"
#include <vector>
#include <string>

using std::vector;
using std::string;


// Implement your logic here.
int countDistinct(std::string str) {
    int n=str.size();
    vector<string> substrings;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j <=n; j++) {
            substrings.push_back(str.substr(i,j-i));
    }
  }
  std::unordered_set<string> us(substrings.begin(),substrings.end());
  return us.size();
}