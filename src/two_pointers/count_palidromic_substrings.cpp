#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

int longestPalindromicSubstring(const std::string& s) {
    int n = s.size();
    int count=0;


    auto expand = [&](int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
    };

    for (int i = 0; i < n; ++i) {
        expand(i, i);       // odd
        expand(i, i + 1);   // even
    }

    return count;
}
