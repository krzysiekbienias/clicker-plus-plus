#include "std_aliases.hpp"
 using namespace stl;

int lengthOfLastWord(string s) {
    int lastWordLength=0;
    int i =s.size();
    while (i>0 && s[i-1]==' ') --i;
    while(i>0 && s[i-1]!=' '){
        --i;
        ++lastWordLength;

    }
    return lastWordLength;
}