# include <string>
#include<vector>

std::string longestPalindromicSubstringExplicite(const std::string& s) {
    int n = s.size();
    if (n == 0) return "";

    int bestStart = 0;
    int bestLen = 1;

    auto expand = [&](int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            int len = right - left + 1;
            if (len > bestLen) {
                bestLen = len;
                bestStart = left;
            }
            left--;
            right++;
        }
    };

    for (int i = 0; i < n; ++i) {
        expand(i, i);       // odd
        expand(i, i + 1);   // even
    }

    return s.substr(bestStart, bestLen);
}