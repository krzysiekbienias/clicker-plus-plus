#include <std_aliases.hpp>

using namespace stl;

string bestDigits(string number, int numDigits)
{
    vector<int> st;
    string result;
    for (char digit : number)
    {
        if (std::isdigit(static_cast<unsigned char>(digit)))
        {
            int currentDigit = digit - '0';
            while (!st.empty() && currentDigit > st.back() && numDigits > 0)
            {
                st.pop_back();
                numDigits--;
            }
            st.push_back(currentDigit);
        }
    }
    while (numDigits > 0)
    {
        st.pop_back();
        numDigits--;
    }
    for (int x : st)
    {
        result += std::to_string(x);
    }
    return result;
}
