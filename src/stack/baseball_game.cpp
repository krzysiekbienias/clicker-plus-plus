#include<vector>
#include<string>
#include "stack/baseball_game.hpp"


int calPoints(std::vector<std::string>& operations) {
    std::vector<int> stack;
    int result=0;
    for (std::string symbol:operations) {
        if (isNumber(symbol)) {
            int numericElement=std::stoi(symbol);
            stack.push_back(numericElement);
        }
        else if (symbol=="C") stack.pop_back();

        else if (symbol=="D") {
            int topElement=stack.back();
            int newElement=topElement*2;
            stack.push_back(newElement);
        }
        else if (symbol=="+") {
            int lastElement=stack.back();
            stack.pop_back();
            int secondToLast=stack.back();
            //restore lastElement
            stack.pop_back();
            stack.push_back(secondToLast);
            stack.push_back(lastElement);
            int newElement=lastElement+secondToLast;
            stack.push_back(newElement);
        }

        }
    for (int el : stack) {
        result+=el;
    }
    return result;
}
