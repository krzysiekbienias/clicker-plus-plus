#include "std_aliases.hpp"

using namespace stl;

string QuestionsMarks(const string &str) {
    int lastDigit=-1;
    int q=0;
    bool foundPair=false;
    int n=str.size();
    for (int i=0;i<n;++i) {
        char c=str[i];
        if (c>='0' && c<='9') {
            int digit=c-'0';
            if (lastDigit!=-1 && lastDigit+digit==10) {
                if (q!=3) return "false";
                else foundPair=true;
            }
            lastDigit=digit;
            q=0;
        }
        else if (c=='?' && lastDigit!=-1) {
            q++;
        }
    }
    if (foundPair==false) return "false";

    return "true";
}
