
#include "stack/reverse_polish_notation.hpp"
#include <vector>
#include <string>

int reversePolishNotation(const std::vector<std::string>& tokens) {
    std::stack<int> st;
    std::unordered_set<std::string> mathSymb={"+","-","*","/"};
    for(std::string el:tokens){
      if (mathSymb.count(el)){
          int n1=st.top();
          st.pop();
          int n2=st.top();
          st.pop();
          switch (el[0]){
            case '+':st.push(n1+n2); break;
            case '-':st.push(n2-n1) ;break;
            case '*':st.push(n2*n1) ;break;
            case '/':st.push(n2/n1) ;break;

            default:break;

          }  
      }
      else{
        st.push(std::stoi(el));
      }
    }
    return st.top();
  }
