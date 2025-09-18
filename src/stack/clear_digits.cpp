#include <string>

std::string clearDigits(std::string s) {
    std::string result="";
    for (char ch :s) {
        if (!std::isdigit(ch)) {
            result.push_back(ch);
        }
        else {
            if (!result.empty())
            //note that we do NOT push the digit, so the digit itself is removed by skipping :)
            result.pop_back();

        }
    }
    return result;
}