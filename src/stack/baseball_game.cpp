#include<vector>
#include<string>
#include "stack/baseball_game.hpp"
#include <stack>

int calPoints(const std::vector<std::string>& operations) {
    std::stack<int> st;
    int result=0;
    for (std::string symbol:operations) {
        if (isNumber(symbol)) {
            int numericElement=std::stoi(symbol);
            st.push(numericElement);
        }
        else if (symbol=="C") st.pop();

        else if (symbol=="D") {
            int topElement=st.top();
            int newElement=topElement*2;
            st.push(newElement);
        }
        else if (symbol=="+") {
            int lastElement=st.top();
            st.pop();
            int secondToLast=st.top();
            //restore lastElement
            st.pop();
            st.push(secondToLast);
            st.push(lastElement);
            int newElement=lastElement+secondToLast;
            st.push(newElement);
        }

        }
    while (!st.empty())
    {
        result+=st.top();
        st.pop();
    }
    return result;
}
