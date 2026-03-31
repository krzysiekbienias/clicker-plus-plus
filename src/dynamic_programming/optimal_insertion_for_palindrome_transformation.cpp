#include <std_aliases.hpp>
#include "dynamic_programming/longest_palindromic_subsequence.hpp"

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
int minInsertions(std::string s) {
    int lcp=longestPalindromeSubseq(s);
    int n=s.size();
    return n-lcp;
}