# include <string>
#include<vector>

std::string longestPalindromicSubstring(const std::string& s) {
    if (s.empty()) return "";
    int start=0;
    int end=0;
    auto expandAroundTheCenter=[&](int left,int right) {
        while (left>=0 && right<s.size() && s[left]==s[right]) {
            --left;
            ++right;
        }
        return right-left-1;
    };
    for (int i=0;i<s.length();++i) {
        int len1=expandAroundTheCenter(i,i); //odd length
        int len2=expandAroundTheCenter(i,i+1);
        int len=std::max(len1,len2);
        if (len>end-start) {
            start=i-(len-1)/2;
            end=i+len/2;
        }
    }//substring method requires start and length that we want to take from s
    return s.substr(start,end-start+1);
}