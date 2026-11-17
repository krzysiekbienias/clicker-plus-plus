#include "strings/count_words_in_sentence.hpp"
#include <vector>
#include <string>


using std::string;


//transition counting
int countWords(std::string s){
    int n= s.size();
    int cnt=0;
    for (int i=0;i<n;i++){
        if(s[i]!=' ' &&  (i=0 || s[i-1]==' ')){
            cnt++;
        }
    }
    return cnt;

}
