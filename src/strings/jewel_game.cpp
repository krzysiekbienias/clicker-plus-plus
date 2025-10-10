#include <std_aliases.hpp>
using namespace stl;

int getMaxScore(string jewels) {
    vector<char> st;
    int result = 0;
    for (int i=0;i<(int)jewels.length();++i) {
        char c=jewels[i];
        if (!st.empty() && (st.back() == c)) {
            result++;
            st.pop_back();
        }
        else st.push_back(c);
    }
    return result;
}
